#include "space_taxi_system.h"
#define AVAILABLE_COUNT 5
using namespace std;

taxi_system::~taxi_system(){
	for (int i = 0; i < passengers.size(); ++i)
	{
		delete passengers[i];
	}
	for (int i = 0; i < drivers.size(); ++i)
	{
		delete drivers[i];
	}
	delete admin;
	delete date_time;
	for (int i = 0; i < codes.size(); ++i)
	{
		delete codes[i];
	}
	for (int i = 0; i < trips.size(); ++i)
	{
		delete trips[i];
	}
	for (int i = 0; i < galaxies.size(); ++i)
	{
		delete galaxies[i];
	}
}

Planet* find_planet(std::vector<Planet*> planets,string planet_name){
	for (int i = 0; i < planets.size(); ++i)
	{
		if(planets[i]->get_name() == planet_name){
			return planets[i];
		}
	}
	return NULL;
}
void print_tree(Planet* root,int in){
	cout<<in<<root->get_name()<<endl;
	std::vector<Planet*> children=root->get_planets();
	for (int i = 0; i < children.size(); ++i)
	{
		print_tree(children[i],in+1);
	}
}
void taxi_system::read_spaceship_models(){
	ifstream file("vehicles.cfg");
	string line;
	while(getline(file,line)){
		int index=line.size()-1;
		line.erase(line.begin()+index);
		models.push_back(line);
	}
	file.close();
}
void taxi_system::read_topology(){
	ifstream file("topology.cfg");
	string line;
	int line_counter=0;
	int number_of_planets=0;
	std::vector<Planet*> planets_in_file;
	while(getline(file,line)){
		if (line_counter == 0)
		{
			line_counter++;
			continue;
		}
		if (line_counter == 1)
		{
			int find=line.find(' ');
			string galaxy_name=line.substr(0,find);
			number_of_planets=stoi(line.substr(find+1));
			galaxies.push_back(new Galaxy(galaxy_name));
			line_counter++;
			continue;
		}
		if (line_counter == 2)
		{
			number_of_planets--;
			int find=line.find(' ');
			string planet_name=line.substr(0,find);
			int planets_count=stoi(line.substr(find+1));
			
			if(find_planet(planets_in_file,planet_name) == NULL){
				Planet* new_planet=new Planet(planet_name);
				planets_in_file.push_back(new_planet);
			}
			Planet* root=find_planet(planets_in_file,planet_name);

			for (int i = 0; i < planets_count; ++i)
			{
				getline(file,line);
				int index=line.size()-1;
				line.erase(line.begin()+index);
				if(find_planet(planets_in_file,line) == NULL){
					Planet* new_planet=new Planet(line);
					planets_in_file.push_back(new_planet);
					root->add_adjacent_planet(new_planet);
				}
			}
			if(number_of_planets == 0){
				galaxies[galaxies.size()-1]->add_root(planets_in_file[0]);
				//print_tree(planets_in_file[0],0);
				planets_in_file.clear();
				line_counter=1;
			}
		}
	}
	file.close();
}
Galaxy* taxi_system::find_galaxy(string galaxy_name){
	for (int i = 0; i < galaxies.size(); ++i)
	{
		if(galaxies[i]->get_name() == galaxy_name){
			return galaxies[i];
		}
	}
	return NULL;
}
int taxi_system::calculate_distance_between(Address* from,Address* to){
	if(from->get_galaxy() == to->get_galaxy()){
		Galaxy* galaxy=find_galaxy(from->get_galaxy());
		
		return galaxy->calculate_distance(from->get_planet(),to->get_planet());
	}
	else{

		Galaxy* from_galaxy=find_galaxy(from->get_galaxy());
		Galaxy* to_galaxy=find_galaxy(to->get_galaxy());
		int from_to_root=from_galaxy->calculate_distance_to(from->get_planet());
		int to_to_root=to_galaxy->calculate_distance_to(to->get_planet());
		return from_to_root+to_to_root;
	}
}
bool taxi_system::find_username(string username){
	for (int i = 0; i < passengers.size(); ++i)
	{
		if(passengers[i]->get_username() == username){
			return true;
		}
	}
	for (int i = 0; i < drivers.size(); ++i)
	{
		if (drivers[i]->get_username() == username)
		{
			return true;
		}
	}
	if(admin->get_username() == username){
		return true;
	}
	return false;
}
bool taxi_system::find_spaceship_number(string number){
	for (int i = 0; i < drivers.size(); ++i)
	{
		if (drivers[i]->get_spaceship_number() == number)
		{
			return true;
		}
	}
	return false;
}
bool taxi_system::find_phone_number(string phone){
	for (int i = 0; i < passengers.size(); ++i)
	{
		if (passengers[i]->get_phone() == phone)
		{
			return true;
		}
	}
	return false;
}
bool is_phone_number(string phone){
	for (int i = 0; i < phone.size(); ++i)
	{
		if(phone[i] < ZERO_ASCII || phone[i]>NINE_ASCII){
			return false;
		}
	}
	return true;
}

bool taxi_system::find_code_in_codes(string code){
	for (int i = 0; i < codes.size(); ++i)
	{
		if(codes[i]->get_code() == code){
			return true;
		}
		/* code */
	}
	return false;
}

bool taxi_system::find_code(string code){
	//int int_code=stoi(code);
	bool result=false;
	int index=-1;
	for (int i = 0; i < codes.size(); ++i)
	{
		if(codes[i]->get_code() == code){
			codes[i]->use_code();
			result=true;
		}
		if(codes[i]->get_counter() == 0){
			index=i;
		}
	}
	if(index != -1){
		delete codes[index];
		codes.erase(codes.begin()+index);
	}
	return result;
}
void taxi_system::register_passenger(string username,string password,string phone_number,string code ,bool has_code){
	if(find_username(username) == true){
		result_line=username+" is not a new username , i have this username in my database!";
		//cout<<username<<" is not a new username , i have this username in my database!"<<endl;
		return;
	}
	if(find_phone_number(phone_number) == true){
		result_line=phone_number+" is not new phone number , i have this in my database!";
		//cout<<phone_number<<" is not new phone number , i have this in my database!"<<endl;
		return;
	}
	if(is_phone_number(phone_number) == false){
		result_line=phone_number+" is not a valid phone number.";
		//cout<<phone_number<<" is not a valid phone number."<<endl;
		return;
	}
	if(!find_code_in_codes(code) && has_code == true){
		result_line=code+" is not a valid discount code!";
		return;
	}
	passengers.push_back(new Passenger(username,password,phone_number,new Date_time(date_time->get_date_time())));
	if(find_code(code)){
		passengers[passengers.size()-1]->set_credit(10);
	}
	result_line = " ";
}
bool taxi_system::find_model(string _spaceship_model){
	for (int i = 0; i < models.size(); ++i)
	{
		if(models[i] == _spaceship_model){
			return true;
		}
	}
	return false;
}
void taxi_system::register_driver(string _user_name,string _password,string _spaceship_number,string _spaceship_model,string _production_year,string _color,bool is_vip){
	if(find_username(_user_name) == true){
		result_line=_user_name+" is not a new username , i have this username in my database!";
		//cout<<_user_name<<" is not a new username , i have this username in my database!"<<endl;
		return;
	}
	if(find_spaceship_number(_spaceship_number) == true){
		result_line=_spaceship_number+" is not a new spaceship number , i have this spaceship number in my database!";
		//cout<<_spaceship_number<<" is not a new spaceship number , i have this spaceship number in my database!"<<endl;
		return;
	}
	if(find_model(_spaceship_model) == false){
		result_line=_spaceship_model+" is not a valid spaceship model!";
		//cout<<_spaceship_model<<" is not a valid spaceship model!"<<endl;
		return;
	}
	if(is_vip == true){
		drivers.push_back(new Vip_driver(_user_name, _password,_spaceship_number,_spaceship_model,_production_year,_color,new Date_time(date_time->get_date_time())));
	}else{
		drivers.push_back(new Driver(_user_name, _password,_spaceship_number,_spaceship_model,_production_year,_color,new Date_time(date_time->get_date_time())));
	}
	result_line=" ";
}
int number_of_digits(int number){
	int counter=0;
	while(number > 0){
		counter++;
		number/=10;
	}
	return counter;
}
User* taxi_system::find_user(string username){
	for (int i = 0; i < passengers.size(); ++i)
	{
		if(passengers[i]->get_username() == username){
			return passengers[i];
		}
	}
	for (int i = 0; i < drivers.size(); ++i)
	{
		if(drivers[i]->get_username() == username){
			return drivers[i];
		}
	}
	if(username == "admin"){
		return admin;
	}
	return NULL;
}
void taxi_system::genarate_discount_code(std::string username){
	string string_code;
	if(find_username(username) && (find_user(username))->get_is_login() && find_user(username)->get_type() == "passenger"){
		for (int i = 0; i < username.size(); ++i)
		{
			int temp=(int)username[i];
			if(i == 0){
				string_code=to_string(temp);
			}else{
				string_code=string_code+to_string(temp);
			}
			
		}
		result_line=string_code+" "+to_string(AVAILABLE_COUNT);
		//cout<<string_code<<' '<<AVAILABLE_COUNT<<endl;
		Code* code=new Code(string_code,(Passenger*)find_user(username));
		codes.push_back(code);
	}else{
		result_line="you can not use this command because you are not login!";
		//cout<<"you can not use this command because you are not login!"<<endl;
	}
}
void taxi_system::login_user(std::string username , std::string password){
	if (find_username(username) && !find_user(username)->get_is_login())
	{
		if(find_user(username)->get_password() == password){
			find_user(username)->login();
			result_line=" ";
		}else{
			result_line="your password is not correct!";
			//cout<<"your password is not correct!"<<endl;
		}
	}else if(find_username(username) == false){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account \"in space taxi system\"!"<<endl;
	}else{
		result_line="you are login , you can not use login command!";
		//cout<<"you are login , you can not use login command!"<<endl;
	}
}
void taxi_system::logout_user(std::string username){
	if (find_username(username) && find_user(username)->get_is_login())
	{
		find_user(username)->logout();
		result_line=" ";
	}else if(find_username(username) == false){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account \"in space taxi system\"!"<<endl;
	}else{
		result_line="you are logout , you can not use logout command!";
		//cout<<"you are logout , you can not use logout command!"<<endl;
	}	
}
void taxi_system::accept_registeration(string username){
	if(admin->get_is_login() && find_username(username) &&find_user(username)->get_type() == "driver"){
		find_user(username)->set_is_accepted(true);
		result_line=" ";
	}else if(!admin->get_is_login()){
		result_line="you can not use \"accept_registeration\" command please login first!";
		cout<<"you can not use \"accept_registeration\" command please login first!"<<endl;
	}else if (!find_username(username))
	{
		result_line="you do not have account \"in space taxi system\"!";
		cout<<"you do not have account \"in space taxi system\"!"<<endl;
	}else{
		result_line=username+" is not a valid username for a driver!";
		cout<<username<<" is not a valid username for a driver!"<<endl;
	}
}
void taxi_system::delete_driver_registeration(string username){
	int index=-1;
	for (int i = 0; i < drivers.size(); ++i)
	{
		if(drivers[i]->get_username() == username){
			index=i;
			break;
		}
	}
	delete drivers[index];
	drivers.erase(drivers.begin()+index);
}
void taxi_system::reject_registeration(string username){
	if(admin->get_is_login() && find_username(username) && find_user(username)->get_type() == "driver"){
		find_user(username)->set_is_accepted(false);
		delete_driver_registeration(username);
		result_line=" ";
	}else if (!find_username(username))
	{
		result_line="you do not have account \"in space taxi system\"!";
		cout<<"you do not have account \"in space taxi system\"!"<<endl;
	}else if(find_user(username)->get_type() != "driver"){
		result_line=username+" is not a valid username for a driver!";
		cout<<username<<" is not a valid username for a driver!"<<endl;
	}else{
		result_line="you can not use \"reject_registeration\" command please login first!";
		cout<<"you can not use \"reject_registeration\" command please login first!"<<endl;
	}
}
void taxi_system::show_registeration_requests(){
	if (admin->get_is_login())
	{
		for (int i = 0; i < drivers.size(); ++i)
		{
			if (!drivers[i]->get_is_accepted())
			{
				result_line=drivers[i]->show_information();
			}
		}
	}else{
		result_line="you can not use \"show_registeration_requests\" command please login first!";
		cout<<"you can not use \"show_registeration_requests\" command please login first!"<<endl;
	}
}
bool taxi_system::find_address(Address* address){
	for (int i = 0; i < galaxies.size(); ++i)
	{
		if(galaxies[i]->get_name() == address->get_galaxy() && galaxies[i]->find_planet(address->get_planet())){
			return true;
		}
	}
	return false;
}
void taxi_system::set_status_available(std::string username,Address* address){
	if(find_username(username) && find_user(username)->get_is_login() && find_address(address) && find_user(username)->get_type() == "driver" && find_user(username)->get_is_accepted()){
		Driver* driver=(Driver*)(find_user(username));
		if(driver->get_status() != "traveling"){
			driver->set_status("available");
			driver->set_address(address);
			result_line=" ";
		}else{
			result_line="you can not change your status to available";
			//cout<<"you can not change your status to available"<<endl;
		}
	}else if(!find_username(username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account \"in space taxi system\"!"<<endl;	
	}else if(!find_user(username)->get_is_login()){
		result_line="you can not use \"set_status\" command please login first!";
		//cout<<"you can not use \"set_status\" command please login first!"<<endl;
	}else if (find_user(username)->get_type() != "driver"){
		result_line=username+" is not a valid username for a driver!";
		//cout<<username<<" is not a valid username for a driver!"<<endl;
	}else if(!find_user(username)->get_is_accepted()){
		result_line="you can not use \"set_status\" command because admin does not accept your registration!";
		//cout<<"you can not use \"set_status\" command because admin does not accept your registration!"<<endl;
	}else{
		result_line="address is not valid!";
		//cout<<"address is not valid!"<<endl;
	}
}
void taxi_system::set_status_unavailable(std::string username){
	if(find_username(username) && find_user(username)->get_is_login() && find_user(username)->get_type() == "driver" && find_user(username)->get_is_accepted()){
		Driver* driver=(Driver*)(find_user(username));
		if(driver->get_status() != "traveling"){
			driver->set_status("unavailable");
			result_line=" ";
		}else{
			result_line="you can not change your status to unavailable";
			//cout<<"you can not change your status to unavailable"<<endl;
		}
	}else if (!find_username(username))
	{
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account \"in space taxi system\"!"<<endl;
	}else if (find_user(username)->get_type() != "driver")
	{
		result_line=username+" is not a valid username for a driver!";
		//cout<<username<<" is not a valid username for a driver!"<<endl;
	}else if (!find_user(username)->get_is_accepted()){
		result_line="you can not use \"set_status\" command because admin does not accept your registration!";
		//cout<<"you can not use \"set_status\" command because admin does not accept your registration!"<<endl;
	}else{
		result_line="you can not use \"set_status\" command please login first!";
		//cout<<"you can not use \"set_status\" command please login first!"<<endl;
	}
}
int taxi_system::calculate_length_of_path(Address* source_address,std::vector<Address*> destinations){
	int sum=0;
	sum+=calculate_distance_between(source_address,destinations[0]);
	for (int i = 0; i < destinations.size()-1; ++i)
	{
		sum+=calculate_distance_between(destinations[i],destinations[i+1]);
	}
	return sum;
}
int taxi_system::calculate_cost_of_trip(bool is_vip,bool is_excellent_passenger,Address* source_address,std::vector<Address*> destinations){
	int result;
	int sum=calculate_length_of_path(source_address,destinations);
	result=sum;
	if(is_vip){
		result = 2*result;
	}if(is_excellent_passenger){
		result= result/2;
	}
	return result;
}
void taxi_system::estimate_trip(std::string username,bool is_vip,Address* source_address,std::vector<Address*> destinations){
	int cost;
	int path_length;
	if (find_username(username) && find_user(username)->get_is_login() && find_address(source_address) && find_user(username)->get_type() == "passenger")
	{
		for (int i = 0; i < destinations.size(); ++i)
		{
			if(!find_address(destinations[i])){
				result_line=string("\"")+destinations[i]->get_galaxy()+","+destinations[i]->get_planet()+"\""+" is not a valid address!";
				//cout<<'\"'<<destinations[i]->get_galaxy()<<','<<destinations[i]->get_planet()<<'\"'<<" is not a valid address!"<<endl;
				return;
			}
		}
		Passenger* passenger=(Passenger*)find_user(username);
		cost=calculate_cost_of_trip(is_vip,passenger->get_is_excellent_passenger(),source_address,destinations);
		path_length=calculate_length_of_path(source_address,destinations);
		result_line=to_string(cost)+" "+to_string(path_length);
		//cout<<cost<<' '<<path_length<<endl;		
	}else if(!find_username(username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if(!find_user(username)->get_is_login()){
		result_line="you can not use \"estimate_trip\" command please login first!";
		//cout<<"you can not use \"estimate_trip\" command please login first!"<<endl;	
	}else if (find_user(username)->get_type() != "passenger")
	{
		result_line=username+" is not a valid username for a passenger!";
		//cout<<username<<" is not a valid username for a passenger!"<<endl;	
	}else{
		result_line=string("\"")+source_address->get_galaxy()+","+source_address->get_planet()+"\""+" is not a valid address!";
		//cout<<'\"'<<source_address->get_galaxy()<<','<<source_address->get_planet()<<'\"'<<" is not a valid address!"<<endl;
	}
}
bool compare_distance(driver_info* one,driver_info* two){
	return one->distance < two->distance;
}
bool compare_rate(driver_info* one , driver_info* two){
	return one->rate > two->rate;
}
void taxi_system::sort_drivers(std::vector<Driver*>& drivers,Address* trip_address){
	std::vector<driver_info*> drivers_information;
	for (int i = 0; i < drivers.size(); ++i)
	{
		driver_info* new_driver_info=new driver_info();
		new_driver_info->driver=drivers[i];
		new_driver_info->distance=calculate_distance_between(trip_address,drivers[i]->get_address());
		new_driver_info->rate=drivers[i]->get_score();
		drivers_information.push_back(new_driver_info);
	}
	sort(drivers_information.begin(),drivers_information.end(),compare_distance);
	if(drivers_information.size() > 4){
		drivers_information.erase(drivers_information.begin()+4,drivers_information.end());
	}
	sort(drivers_information.begin(),drivers_information.end(),compare_rate);
	drivers.clear();
	for (int i = 0; i < drivers_information.size(); ++i)
	{
		drivers.push_back(drivers_information[i]->driver);
	}
	for (int i = 0; i < drivers_information.size(); ++i)
	{
		delete drivers_information[i];
	}
}
bool taxi_system::send_trip_to_drivers(Trip*& trip){
	int number_of_recivers=4;
	Address* source_address=trip->get_address();
	std::vector<Driver*> candidates;
	string model=trip->get_model();
	for (int i = 0; i < drivers.size(); ++i)
	{
		if(drivers[i]->get_driver_status() == "available" && drivers[i]->get_address_galaxy() == source_address->get_galaxy() && model == "vip" && drivers[i]->get_model() == "vip" ){
			candidates.push_back(drivers[i]);
		}if(drivers[i]->get_driver_status() == "available" && drivers[i]->get_address_galaxy() == source_address->get_galaxy() && model != "vip" && drivers[i]->get_model() != "vip"){
			candidates.push_back(drivers[i]);
		}
	}
	if (candidates.size() != 0)
	{
		sort_drivers(candidates,trip->get_address());
		for (int i = 0; i < candidates.size(); ++i)
		{
			candidates[i]->add_trip(trip);
		}
		return true;
	}else{
		return false;
	}
}
void taxi_system::request_trip(std::string username, bool is_vip,Address* source_address,std::vector<Address*> destinations){
	if(find_username(username) && find_user(username)->get_is_login() && find_user(username)->get_type() == "passenger" && find_user(username)->get_status()=="available" && find_user(username)->rate_all_trips() && find_address(source_address)){
		for (int i = 0; i < destinations.size(); ++i)
		{
			if(!find_address(destinations[i])){
				result_line=string("\"")+destinations[i]->get_galaxy()+","+destinations[i]->get_planet()+"\""+" is not a valid address!";
				//cout<<'\"'<<destinations[i]->get_galaxy()<<','<<destinations[i]->get_planet()<<'\"'<<" is not a valid address!"<<endl;
				return;
			}
		}
		Passenger* passenger=(Passenger*)find_user(username);
		int cost=calculate_cost_of_trip(is_vip,passenger->get_is_excellent_passenger(),source_address,destinations);
		int distance=calculate_length_of_path(source_address,destinations);
		
		if(passenger->get_credit() >= cost-10){
			if(is_vip){
				trips.push_back(new Vip_trip(username,source_address,destinations,cost,distance,new Date_time(date_time->get_date_time())));
				passenger->add_trip(trips[trips.size()-1]);
				passenger->set_address(new Address(source_address->get_galaxy(),source_address->get_planet()));

				if(!send_trip_to_drivers(trips[trips.size()-1])){
					result_line="sorry.i can not find any drivers near you.i remove your trip requst!";
					//cout<<"sorry.i can not find any drivers near you.i remove your trip requst!"<<endl;
					passenger->cancel_trip();
					delete trips[trips.size()-1];
					int index=trips.size()-1;
					trips.erase(trips.begin()+index);
					return;
				}
				result_line=to_string(cost)+" "+to_string(distance);
				//cout<<cost<<' '<<distance<<endl;
			}else{
				trips.push_back(new Trip(username,source_address,destinations,cost,distance,new Date_time(date_time->get_date_time())));
				passenger->add_trip(trips[trips.size()-1]);
				
				if(!send_trip_to_drivers(trips[trips.size()-1])){
					result_line="sorry.i can not find any drivers near you.i remove your trip requst!";
					//cout<<"sorry.i can not find any drivers near you.i remove your trip requst!"<<endl;
					passenger->cancel_trip();
					delete trips[trips.size()-1];
					int index=trips.size()-1;
					trips.erase(trips.begin()+index);
					return;	
				}
				result_line=to_string(cost)+" "+to_string(distance);
				//cout<<cost<<' '<<distance<<endl;
			}
		}else{
			result_line="you do not have enough money to request this trip!";
			//cout<<"you do not have enough money to request this trip!"<<endl;
		}

	}else if(!find_username(username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if(!find_user(username)->get_is_login()){
		result_line="you can not use \"request_trip\" command please login first!";
		//cout<<"you can not use \"request_trip\" command please login first!"<<endl;	
	}else if(find_user(username)->get_type() != "passenger"){
		result_line=username+" is not a valid username for a passenger!";
		//cout<<username<<" is not a valid username for a passenger!"<<endl;
	}else if(find_user(username)->get_status() != "available"){
		result_line="you are traveling and you can not request new trip!";
		//cout<<"you are traveling and you can not request new trip!"<<endl;
	}else if(find_user(username)->rate_all_trips() == false){
		result_line="you can not use \"request_trip\" command please rate your trip first!";
		//cout<<"you can not use \"request_trip\" command please rate your trip first!"<<endl;
	}else{
		result_line=string("\"")+source_address->get_galaxy()+","+source_address->get_planet()+"\""+" is not a valid address!";
		//cout<<'\"'<<source_address->get_galaxy()<<','<<source_address->get_planet()<<'\"'<<" is not a valid address!"<<endl;
	}
}
void taxi_system::delete_request_in_driver(Trip* trip){
	for (int i = 0; i < drivers.size(); ++i)
	{
		if(drivers[i]->find_trip(trip) == true){
			drivers[i]->erase_request(trip);
		}
	}
}
void taxi_system::cancel_trip_request(std::string username){
	if(find_username(username) && find_user(username)->get_is_login() && find_user(username)->get_type() == "passenger"){
		Passenger* passenger=(Passenger*)find_user(username);
		int index=-1;
		for (int i = 0; i < trips.size(); ++i)
		{
			if(trips[i] == passenger->get_trip() && !trips[i]->get_is_accepted()){
				index=i;
				break;
			}
		}
		passenger->cancel_trip();
		if(index >= 0){
			delete_request_in_driver(trips[index]);
			delete trips[index];
			trips.erase(trips.begin()+index);
			result_line=" ";
		}else{
			result_line="you can not cancel your trip request!";
			//cout<<"you can not cancel your trip request!"<<endl;
		}
		
	}else if(!find_username(username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if(find_user(username)->get_type() != "passenger"){
		result_line=username+" is not a valid username for a passenger!";
		//cout<<username<<" is not a valid username for a passenger!"<<endl;
	}else{
		result_line="you can not use \"cancel_trip_request\" command please login first!";
		//cout<<"you can not use \"cancel_trip_request\" command please login first!"<<endl;
	}
}
void taxi_system::show_trip_requests(std::string username){
	if(find_username(username) && find_user(username)->get_is_login() && find_user(username)->get_type() == "driver" && find_user(username)->get_is_accepted() && find_user(username)->get_status() == "available"){
		Driver* driver=(Driver*)find_user(username);
		result_line=driver->show_requests();
	}else if(!find_username(username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if(find_user(username)->get_type() != "driver"){
		result_line=username+" is not a valid username for a driver!";
		//cout<<username<<" is not a valid username for a driver!"<<endl;
	}else if(!find_user(username)->get_is_accepted()){
		result_line="you can not use \"show_trip_requests\" command because admin does not accept your registration!";
		//cout<<"you can not use \"show_trip_requests\" command because admin does not accept your registration!"<<endl;
	}else if(find_user(username)->get_status() != "available"){
		result_line="you can not use \"show_trip_requests\" command because your status is not available!";
	}
	else{
		result_line="you can not use \"show_trip_requests\" command please login first!";
		//cout<<"you can not use \"show_trip_requests\" command please login first!"<<endl;
	}
}
void taxi_system::accept_trip_request(string driver_username,string passenger_username){
	if(find_username(driver_username) && find_user(driver_username)->get_is_login() && find_username(passenger_username) && find_user(driver_username)->get_type() == "driver" && find_user(driver_username)->get_is_accepted() && find_user(driver_username)->get_status() == "available"){
		find_user(driver_username)->set_status("traveling");
		Driver* driver=(Driver*)find_user(driver_username);
		if(driver->find_trip_for_accept()){
			for (int i = 0; i < trips.size(); ++i)
			{
				if(trips[i]->get_username() == passenger_username && trips[i]->get_is_accepted() == false){
					trips[i]->set_is_accepted(true);
					trips[i]->set_driver_name(driver_username);
					Passenger* passenger=(Passenger*) find_user(passenger_username);
					passenger->set_trip_accepted();
					for (int i = 0; i < drivers.size(); ++i)
					{
						if(drivers[i]->find_trip(trips[i]) == true && drivers[i]->get_username() != driver_username){
							drivers[i]->erase_request(trips[i]);
						}
					}
					break;
				}
			}
			result_line=" ";
		}else{
			//cout<<"you do not have trip for acceptting!"<<endl;
		 	result_line= "you do not have trip for acceptting!";
		 }
	}else if (!find_username(driver_username))
	{
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if (!find_user(driver_username)->get_is_login())
	{
		result_line="you can not use \"accept_trip_request\" command please login first!";
		//cout<<"you can not use \"accept_trip_request\" command please login first!"<<endl;	
	}else if(find_user(driver_username)->get_type() != "driver"){
		result_line=driver_username+" is not a valid username for a driver!";
		//cout<<driver_username<<" is not a valid username for a driver!"<<endl;
	}else if(!find_user(driver_username)->get_is_accepted()){
		result_line="you can not use \"accept_trip_request\" command because admin does not accept your registration!";
		//cout<<"you can not use \"accept_trip_request\" command because admin does not accept your registration!"<<endl;
	}else if(find_user(driver_username)->get_status() == "available"){
		result_line="you can not use \"accept_trip_request\" command because your status is not available!";
	}else{
		result_line="\" passenger_username \" does not have account in space taxi system!";
		//cout<<"\" passenger_username \" does not have account in space taxi system!"<<endl;
	}
}
void taxi_system::trip_status(string passenger_username){
	if(find_username(passenger_username) && find_user(passenger_username)->get_is_login() && find_user(passenger_username)->get_type() == "passenger"){
		Passenger* passenger=(Passenger*)find_user(passenger_username);
		if(passenger->get_trip() != NULL){
			if( passenger->get_trip() != NULL && (passenger->get_trip())->get_is_accepted()){
				for (int i = 0; i < drivers.size(); ++i)
				{
					if(drivers[i]->get_username() == (passenger->get_trip())->get_driver_name()){
						result_line=string("accepted ")+drivers[i]->get_username()+" "+drivers[i]->get_address_galaxy()+","+drivers[i]->get_address_planet()+" "+drivers[i]->get_spaceship_model()+" "+drivers[i]->get_spaceship_color();
						//cout<<"accepted"<<' '<<drivers[i]->get_username()<<' '<<drivers[i]->get_address_galaxy()<<','<<drivers[i]->get_address_planet()<<' '<<drivers[i]->get_spaceship_model()<<' '<<drivers[i]->get_spaceship_color()<<endl;
					}
				}
			}else{
				if(!(passenger->get_trip())->get_is_accepted()){
					//cout<<"ACCEPT WRONG!"<<endl;
				}
				result_line="waiting";
				//cout<<"waiting"<<endl;
			}
	}else{
		result_line="you do not have any trip requests in system!";
	}
	}else if (!find_username(passenger_username))
	{
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if (!find_user(passenger_username)->get_is_login())
	{
		result_line="you can not use \"trip_status\" command please login first!";
		//cout<<"you can not use \"trip_status\" command please login first!"<<endl;
	}else{
		result_line=passenger_username+" is not a valid username for a passenger!";
		//cout<<passenger_username<<" is not a valid username for a passenger!"<<endl;
	}
}
void taxi_system::arrived(string driver_username){
	if (find_username(driver_username) && find_user(driver_username)->get_is_login() && find_user(driver_username)->get_type() == "driver" && find_user(driver_username)->get_is_accepted())
	{
		for (int i = 0; i < trips.size(); ++i)
		{
			if(trips[i]->get_is_accepted() && !trips[i]->get_is_finished() && trips[i]->get_driver_name() == driver_username){
				find_user(trips[i]->get_username())->set_status("traveling");
				trips[i]->set_start_time(new Date_time(date_time->get_date_time()));
			}
		}
		determine_excellent_passengers(date_time);
		result_line=" ";
	}else if(!find_username(driver_username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if(find_user(driver_username)->get_type() != "driver"){
		result_line=driver_username+" is not a valid username for a driver!";
		//cout<<driver_username<<" is not a valid username for a driver!"<<endl;
	}else if(!find_user(driver_username)->get_is_accepted()){
		result_line="you can not use \"arrived\" command because admin does not accept your registration!";
		//cout<<"you can not use \"arrived\" command because admin does not accept your registration!"<<endl;
	}else{
		result_line="you can not use \"arrived\" command please login first!";
		//cout<<"you can not use \"arrived\" command please login first!"<<endl;
	}
}
void taxi_system::end_trip(string driver_username){
	if (find_username(driver_username) && find_user(driver_username)->get_is_login() && find_user(driver_username)->get_type() == "driver" && find_user(driver_username)->get_is_accepted())
	{
		for (int i = 0; i < trips.size(); ++i)
		{
			if(trips[i]->get_is_accepted() && !trips[i]->get_is_finished() && trips[i]->get_driver_name() == driver_username){
				trips[i]->set_is_finished(true);
				find_user(trips[i]->get_username())->set_status("available");
				Passenger* passenger=(Passenger*)find_user(trips[i]->get_username());
				passenger->reduce_credit(trips[i]->get_credit());
				credit+=trips[i]->get_credit();
				find_user(trips[i]->get_driver_name())->set_address(new Address((trips[i]->get_destination())->get_galaxy(),(trips[i]->get_destination())->get_planet()));
				find_user(trips[i]->get_driver_name())->set_status("available");
				trips[i]->set_end_time(new Date_time(date_time->get_date_time()));
			}	
		}
		result_line=" ";
	}else if(!find_username(driver_username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if(find_user(driver_username)->get_type() != "driver"){
		result_line=driver_username+" is not a valid username for a driver!";
		//cout<<driver_username<<" is not a valid username for a driver!"<<endl;
	}else if(!find_user(driver_username)->get_is_accepted()){
		result_line="you can not use \"end_trip\" command because admin does not accept your registration!";
		//cout<<"you can not use \"end_trip\" command because admin does not accept your registration!"<<endl;
	}else{
		result_line="you can not use \"end_trip\" command please login first!";
		//cout<<"you can not use \"end_trip\" command please login first!"<<endl;
	}
}
void taxi_system::rate_driver(string username,int rate){
	if(find_username(username) && find_user(username)->get_is_login() && find_user(username)->get_type() == "passenger"){
		Passenger* passenger=(Passenger*)find_user(username);
		if(!passenger->rate_all_trips() && (passenger->get_trip())->get_is_accepted() && (passenger->get_trip())->get_is_finished() && rate >= 1 && rate <= 10){
			(passenger->get_trip())->set_is_rated(true);
			Driver* driver=(Driver*)find_user((passenger->get_trip())->get_driver_name());
			driver->add_rate(rate);
			driver->set_trip_rate(rate);
			result_line=" ";
		}else if(rate < 1 || rate > 10){
			result_line=to_string(rate)+" is not a valid rate , rate number is between 1 and 10 !";
			//cout<<rate<<" is not a valid rate , rate number is between 1 and 10 !"<<endl;
		}
		else{
			result_line="you can not use \" rate_driver\" command , you rate all trips!";
			//cout<<"you can not use \" rate_driver\" command , you rate all trips!"<<endl;
		}
	}else if(!find_username(username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if (find_user(username)->get_type() != "passenger"){
		result_line=username+" is not a valid username for a passenger!";
		//cout<<username<<" is not a valid username for a passenger!"<<endl;
	}else{
		result_line="you can not use \"rate_driver\" command please login first!";
		//cout<<"you can not use \"rate_driver\" command please login first!"<<endl;
	}
}
void taxi_system::charge_account(string username,int credit){
	if (find_username(username) && find_user(username)->get_is_login() && find_user(username)->get_type() == "passenger"){
		find_user(username)->set_credit(find_user(username)->get_credit()+credit);
		result_line=" ";
	}else if(!find_username(username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if(!find_user(username)->get_is_login()){
		result_line="you can not use \"charge_account\" command please login first!";
		//cout<<"you can not use \"charge_account\" command please login first!"<<endl;	
	}else{
		result_line=username+" is not a valid username for a passenger!";
		//cout<<username<<" is not a valid username for a passenger!"<<endl;	
	}
}
void taxi_system::get_credit(string username){
	if (find_username(username) && find_user(username)->get_is_login() && find_user(username)->get_type() == "passenger"){
		result_line=to_string(find_user(username)->get_credit());
		//cout<<find_user(username)->get_credit()<<endl;
	}else if(!find_username(username)){
		result_line="you do not have account \"in space taxi system\"!";
		//cout<<"you do not have account in space taxi system!"<<endl;
	}else if(!find_user(username)->get_is_login()){
		result_line="you can not use \"get_credit\" command please login first!";
		//cout<<"you can not use \"get_credit\" command please login first!"<<endl;	
	}else{
		result_line=username+" is not a valid username for a passenger!";
		//cout<<username<<" is not a valid username for a passenger!"<<endl;	
	}	
}
void taxi_system::determine_excellent_passengers(Date_time* date_time){
	
	for (int i = 0; i < passengers.size(); ++i)
	{	
		if(passengers[i]->get_num_of_trips() >= 3){
			
		}
		if(!passengers[i]->get_is_excellent_passenger() && passengers[i]->get_num_of_trips() >= 3 ){
			string distance_between=passengers[i]->get_gap_between_last_trips();
			//cout<<distance_between<<endl;
			provide_date_time(distance_between);
			//cout<<distance_between<<endl;
			if(distance_between < "1-00:00:00"){
				passengers[i]->set_is_excellent_passenger(true);
			}
		}else if (passengers[i]->get_is_excellent_passenger()){
			string gap_between=passengers[i]->get_last_trip_gap_with(date_time->get_date_time());
			//cout<<gap_between<<endl;
			provide_date_time(gap_between);
			//cout<<gap_between<<endl;
			if( gap_between > "2-00:00:00"){
				passengers[i]->set_is_excellent_passenger(false);
			}
		}
	}
}
void taxi_system::provide_date_time(string& date_time){
	int find_dash=date_time.find('-');
	if(find_dash <= 0){
		throw bad_command_exception(date_time+" is not a valid date time!");
	}
	string day=date_time.substr(0,find_dash);
	if(day[0] == '0' && day.size() == 2){
		day=day.substr(1);
	}
	string temp=date_time.substr(find_dash+1);
	std::vector<string> params;
	while(temp.find(':') != -1){
		int find=temp.find(':');
		params.push_back(temp.substr(0,find));
		temp=temp.substr(find+1);
	}
	params.push_back(temp);
	for (int i = 0; i < params.size(); ++i)
	{
		if(params[i].size() == 1){
			string result=params[i];
			params[i]=string("0")+result;
		}
	}
	string final_result=day+"-"+params[0]+":"+params[1]+":"+params[2];
	date_time=final_result;
	//cout<<final_result<<endl;
}
void taxi_system::set_time(string _date_time){
	if(admin->get_is_login()){
		for (int i = 0; i < trips.size(); ++i)
		{
			if(trips[i]->get_is_finished() && trips[i]->get_end_time() == date_time->get_date_time()){
				int driver_credit=find_user(trips[i]->get_driver_name())->get_credit()+(trips[i]->get_credit()*8)/10;
				find_user(trips[i]->get_driver_name())->set_credit(driver_credit);
				
				credit-=(trips[i]->get_credit()*8)/10;
				
			}
		}
		provide_date_time(_date_time);
		delete date_time;
		date_time=new Date_time(_date_time);
		determine_excellent_passengers(date_time);
	}else{
		cout<<"you can not use \"set_time\" command please login first!"<<endl;
	}
}
void taxi_system::passenger_report(string username){
	if (admin->get_is_login() && find_username(username) && find_user(username)->get_type() == "passenger")
	{
		cout<<find_user(username)->get_credit()<<endl;
		result_line=" ";
	}else if (!find_username(username))
	{
		cout<<"\""<<username<<"\""<<" does not have account in space taxi system!"<<endl;
	}else if(!admin->get_is_login()){
		cout<<"you can not use \"passenger_report\" command please login first!"<<endl;
	}else{
		cout<<username<<" is not a valid username for a passenger!"<<endl;
	}
}
void taxi_system::driver_report(string username,string from_date,string to_date){
	string from=from_date;
	string to=to_date;
	provide_date_time(from);
	provide_date_time(to);
	if (admin->get_is_login() && find_username(username) && find_user(username)->get_type() == "driver")
	{
		if(from <= date_time->get_date_time() && to <= date_time->get_date_time() && from <= to){
			Driver* driver = (Driver*)find_user(username);
			driver->show_report(from , to);
			result_line=" ";
		}else{
			cout<<"from_date_time "<<from_date<<" and "<<to_date<<" are not valid date_times!"<<endl;
		}
	}else if(!find_username(username)){
		cout<<"\""<<username<<"\""<<" does not have account in space taxi system!"<<endl;
	}else if(!admin->get_is_login()){
		cout<<"you can not use \"driver_report\" command please login first!"<<endl;
	}else{
		cout<<username<<" is not a valid username for a driver!"<<endl;	
	}
}
void taxi_system::system_report(){
	if (admin->get_is_login())
	{
		int drivers_count=0;
		for (int i = 0; i < drivers.size(); ++i)
		{
			string temp=drivers[i]->get_username();
		
			if(find_user(temp)->get_is_accepted()){
				drivers_count++;
			}
		}
		cout<<credit<<' '<<trips.size()<<' '<<drivers_count<<' '<<passengers.size()<<endl;
		result_line=" ";
	}else{
		cout<<"you can not use \"system_report\" command please login first!"<<endl;
	}
}
int taxi_system::system_credit(string from_date,string to_date){
	int credit=0;
	for (int i = 0; i < trips.size(); ++i)
	{
		if(trips[i]->get_start_time() >= from_date && trips[i]->get_end_time() <= to_date && trips[i]->get_is_finished()){
			int temp=trips[i]->get_credit();
			credit+=temp-((temp*8)/10);
		}
	}
	return credit;
}
int taxi_system::number_of_trips(string from_date,string to_date){
	int counter=0;
	for (int i = 0; i < trips.size(); ++i)
	{
		if(trips[i]->get_start_time() >= from_date && trips[i]->get_end_time() <= to_date && trips[i]->get_is_finished()){
			counter++;
		}	
	}
	return counter;
}
int taxi_system::number_of_drivers(string from_date,string to_date){
	int counter=0;
	for (int i = 0; i < drivers.size(); ++i)
	{
		User* user=drivers[i];
		if((user->get_birth_time())->get_date_time() >= from_date && (user->get_birth_time())->get_date_time() <= to_date && user->get_is_accepted() ){
			counter++;
		}
	}
	return counter;
}
int taxi_system::number_of_passengers(string from_date,string to_date){
	int counter=0;
	for (int i = 0; i < passengers.size(); ++i)
	{
		User* user=passengers[i];
		if((user->get_birth_time())->get_date_time() >= from_date && (user->get_birth_time())->get_date_time() <= to_date){
			counter++;
		}
	}
	return counter;
}
void taxi_system::system_report_with_date(string from_date,string to_date){
	string from=from_date;
	string to=to_date;
	provide_date_time(from);
	provide_date_time(to);
	if (admin->get_is_login())
	{
		if(from <= date_time->get_date_time() && to <= date_time->get_date_time() && from <= to){
			cout<<credit<<' '<<number_of_trips(from,to)<<' '<<number_of_drivers(from,to)<<' '<<number_of_passengers(from,to)<<endl;
			result_line=" ";
		}else{
			cout<<"from_date_time "<<from_date<<" and "<<to_date<<" are not valid date_times!"<<endl;	
		}
	}else{
		cout<<"you can not use \"system_report\" command please login first!"<<endl;	
	}
}
 void taxi_system::get_system_time(){
 	result_line = date_time->get_date_time();
 }