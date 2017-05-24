#ifndef PASSENGER_CLIENT_H
#define PASSENGER_CLIENT_H

#include "client_socket.h"
#include "command.h"
#include <cstdlib>

class passenger_client
{
public:
	passenger_client(std::string address, int port);
  	void handel_passenger_commands();
  	void do_UI_command(std::string command);
  	void logout();
  	bool get_find_username(){return find_username;}
  	std::string get_result(){return result;}
	std::string get_username(){return username;}
    std::string get_credit();
    std::string get_date_time();
	void set_username(std::string _username){username = _username; find_username = true;}
private:
	
	ClientSocket* passenger_socket;
	std::string address;
	std::string result;
	int port;
 	std::string username;
 	bool find_username;
 	bool send_register_command;
 	void do_passenger_commands(Command* command,bool& do_command);
 	void do_trip_commands(Command* command,bool& do_command);
};

#endif
