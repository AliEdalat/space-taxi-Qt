#include "passenger_client.h"  

using namespace std;

void passenger_client::do_passenger_commands(Command* command,bool& do_command){
	if(command->get_type() == "get_discount_code" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
		do_command=true;
  	}
  	do_trip_commands(command,do_command);
  	if(command->get_type() == "rate_driver" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 1){
    	do_command=true;
  	}if(command->get_type() == "get_credit" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
    	do_command=true;
  	}if(command->get_type() == "charge_account" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 1){
    	do_command=true;
  	}if(command->get_type() == "register" && (command->get_num_of_parameters() == 3 || command->get_num_of_parameters() == 4) && (command->get_num_of_spaces() == 3 || command->get_num_of_spaces() == 4)){
  		if(find_username == false){ 
        	send_register_command=true;
        	username = command->get_parameter(0);
    		find_username=true;
      	}
    	do_command=true;
  	}if (command->get_type() == "login" && command->get_num_of_parameters() == 2){
    	if(find_username == false){ 
        	send_register_command=true;
        	username = command->get_parameter(0);
    		find_username=true;
      	}
    	do_command=true;
  	}if(command->get_type() == "logout" && command->get_num_of_parameters() == 0){
    	do_command=true;
        find_username = false;
  	}
}
void passenger_client::do_trip_commands(Command* command,bool& do_command){
	if (command->get_type() == "estimate_trip" && command->get_num_of_parameters() >=2){
    	do_command=true;
  	}if (command->get_type() == "request_trip" && command->get_num_of_parameters() >=2){
    	do_command=true;
  	}
  	if(command->get_type() == "cancel_trip_request" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
    	do_command=true;
  	}if(command->get_type() == "trip_status" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
    	do_command=true;
  	}
}
string provide_command(string line , string username){
	string _user_name=username;
	if(line.find("register") != -1){
		int found=line.find(' ');
		string temp2=line.substr(found);
		int find=temp2.find(_user_name);
		if(find == -1){
			throw invalid_command("you can not use this command because you use register command before this time!");
		}
		string temp=temp2.substr(find);
		find=temp.find(' ');
		temp=temp.substr(find+1);
		return _user_name+" "+"register_passenger"+" "+temp;
  	}else if(line.find("login") != -1){
  		int found=line.find(' ');
		string temp2=line.substr(found);
  		int find=temp2.find(_user_name);
  		if(find == -1){
			throw invalid_command("i can not find your username in command!");
		}
		string temp=temp2.substr(find);
		find=temp.find(' ');
		temp=temp.substr(find+1);
		return _user_name+" "+"login"+" "+temp;
  	}
  	return _user_name+" "+line;
}
void passenger_client::handel_passenger_commands(){
	ClientSocket socket(address , port);
  	cout << "# connection established\n";
	string line;
  	while (getline(cin, line)) {
    	if (line == ":q")
      		break;
  		try{
      		Command* command=new Command(line);
      		bool do_command= false;
      		do_passenger_commands(command,do_command);
      		if(do_command == false){
        		cout<<"\""<<line<<"\" is not a valid passenger command!"<<endl;
        		continue;
      		}
      		if(find_username == false){
  				cout<<"you must register yourself in space taxi system!"<<endl;
  				continue;
  			}else{
  				line=provide_command(line,username);
  			}
  		}catch(invalid_command bad_command){
    		cout<<bad_command.get_error()<<endl;
    		continue;
  		}
  		
    	//cout<<"BEFORE_SEND :"<<line<<endl;
    	socket.send(line);
    	string temp=socket.receive();
    	if((send_register_command == true && temp != " ") || temp == "you do not have account \"in space taxi system\"!"){
    		find_username=false;
    		send_register_command=false;
    	}else{
    		send_register_command=false;
    	}
      result=temp;
    	cout << temp << endl;
    	socket.status();
  	}
}
void passenger_client::do_UI_command(string command){
  
try{
      Command* _command=new Command(command);
      bool do_command= false;
      do_passenger_commands(_command,do_command);
      if(do_command == false){
        result=string("\"")+command+"\" is not a valid passenger command!";
        cout<<"\""<<command<<"\" is not a valid passenger command!"<<endl;
        return;
      }
      if(find_username == false){
        result="you must register yourself in space taxi system!";
        cout<<"you must register yourself in space taxi system!"<<endl;
        return;
      }else{
        command=provide_command(command,username);
      }
    }catch(invalid_command bad_command){
      result=bad_command.get_error();
      cout<<bad_command.get_error()<<endl;
      return;
    }
    
    //cout<<"BEFORE_SEND :"<<line<<endl;
    passenger_socket->send(command);
    string temp=passenger_socket->receive();
    if((send_register_command == true && temp != " ") || temp == "you do not have account \"in space taxi system\"!"){
      find_username=false;
      send_register_command=false;
    }else{
      send_register_command=false;
    }
    result=temp;
    cout << temp << endl;
    passenger_socket->status();
}
void passenger_client::logout(){
  string command=username+" logout";
  passenger_socket->send(command);
  passenger_socket->receive();
  find_username = false;
}
string passenger_client::get_credit(){
    string command=username + " get_credit";
    passenger_socket->send(command);
    return passenger_socket->receive();
}

string passenger_client::get_date_time(){
    string command=username + " get_system_time";
    passenger_socket->send(command);
    return passenger_socket->receive();
}

passenger_client::passenger_client(string _address, int _port){
	passenger_socket= new ClientSocket(_address , _port);
    find_username=false;
	send_register_command=false;
	port=_port;
	address=_address;
}
