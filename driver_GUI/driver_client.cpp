#include "driver_client.h"

using namespace std;

void driver_client::do_driver_commands(Command* command,bool& do_command){
	if (command->get_type() == "register" && (command->get_num_of_parameters() == 7 || command->get_num_of_parameters() == 6) && (command->get_num_of_spaces() == 6 || command->get_num_of_spaces() == 7)){
		if(command->get_num_of_parameters() == 7 && command->get_parameter(6) == "VIP"){
			if(find_username == false){
				username=command->get_parameter(0);
				find_username=true;
				send_register_command=true;
			}
			do_command=true;
		}else if(command->get_num_of_parameters() == 6 && command->get_parameter(5) != "VIP"){
			if(find_username == false){
				username=command->get_parameter(0);
				find_username=true;
				send_register_command=true;
			}
			do_command=true;	
		}
	}
	if (command->get_type() == "login" && command->get_num_of_parameters() == 2 && command->get_num_of_spaces() == 2){
		if(find_username == false){
			username=command->get_parameter(0);
			find_username=true;
			send_register_command=true;
		}
		do_command=true;
	}if(command->get_type() == "logout" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
        do_command=true;
        find_username = false;
	}
	if(command->get_type() == "set_status" && command->get_num_of_parameters() == 2 && command->get_parameter(0) == "available" && command->get_num_of_spaces() == 2){
		do_command=true;
	}if(command->get_type() == "set_status" && command->get_num_of_parameters() == 1 && command->get_parameter(0) == "unavailable" && command->get_num_of_spaces() == 1){
		do_command=true;
	}if(command->get_type() == "show_trip_requests" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
		do_command=true;
	}if (command->get_type() == "accept_trip_request" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 1){
		do_command=true;
	}if (command->get_type() == "arrived" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
		do_command=true;
	}if(command->get_type() == "end_trip" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
		do_command=true;
	}
}

string provide_command(string line , string username){
	string _user_name=username;
	if(line.find("register") != -1){
		int found=line.find(' ');
		string temp2=line.substr(found);
		//cout<<temp2<<endl;
		int find=temp2.find(_user_name);
		if(find == -1){
			throw invalid_command("you can not use this command because you use register command befor this time!");
		}
		string temp=temp2.substr(find);
		find=temp.find(' ');
		//cout<<temp<<endl;
		temp=temp.substr(find+1);
		//cout<<temp<<endl;
		return _user_name+" "+"register_driver"+" "+temp;
  	}if(line.find("login") != -1){
  		int found=line.find(' ');
		string temp2=line.substr(found);
		//cout<<temp2<<endl;
  		int find=temp2.find(_user_name);
  		if(find == -1){
			throw invalid_command("i can not find your username in command!");
		}
		string temp=temp2.substr(find);
		find=temp.find(' ');
		temp=temp.substr(find+1);
		//cout<<temp<<endl;
		return _user_name+" "+"login"+" "+temp;
  	}
  	return _user_name+" "+line;
}

void driver_client::handel_driver_commands(){
	ClientSocket socket(address , port);
  	cout << "# connection established\n";
	string line;
  	while (getline(cin, line)) {
    	if (line == ":q")
      		break;
  		try{
      		Command* command=new Command(line);
      		bool do_command= false;
      		do_driver_commands(command,do_command);
      		if(do_command == false){
        		cout<<"\""<<line<<"\" is not a valid driver command!"<<endl;
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
    	cout << temp << endl;
    	socket.status();
  	}
}

void driver_client::do_UI_command(string command){
cout<<command<<endl;
try{
      Command* _command=new Command(command);
      bool do_command= false;
      do_driver_commands(_command,do_command);
      if(do_command == false){
        result=string("\"")+command+"\" is not a valid driver command!";
        cout<<"\""<<command<<"\" is not a valid driver command!"<<endl;
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
    driver_socket->send(command);
    string temp=driver_socket->receive();
    if((send_register_command == true && temp != " ") || temp == "you do not have account \"in space taxi system\"!"){
      find_username=false;
      send_register_command=false;
    }else{
      send_register_command=false;
    }
    result=temp;
    cout << temp << endl;
    driver_socket->status();
}

void driver_client::logout(){
  string command=username+" logout";
  driver_socket->send(command);
  driver_socket->receive();
  find_username = false;
}

driver_client::driver_client(string _address, int _port){
    driver_socket= new ClientSocket(_address , _port);
    find_username=false;
	send_register_command=false;
	port=_port;
	address=_address;
}