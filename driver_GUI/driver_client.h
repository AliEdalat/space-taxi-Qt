#ifndef DRIVER_CLIENT_H
#define DRIVER_CLIENT_H

#include "client_socket.h"
#include "command.h"
#include <cstdlib>

class driver_client
{
public:
	driver_client(std::string address, int port);
  	void handel_driver_commands();
    void do_UI_command(std::string command);
    void logout();
    bool get_find_username(){return find_username;}
    std::string get_result(){return result;}
    std::string get_username(){return username;}
private:
    ClientSocket* driver_socket;
    std::string result;
	std::string address;
	int port;
 	std::string username;
 	bool find_username;
 	bool send_register_command;
 	void do_driver_commands(Command* command,bool& do_command);
};

#endif
