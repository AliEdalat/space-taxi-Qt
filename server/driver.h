#ifndef DRIVER_H
#define DRIVER_H

#include "user.h"
#include "spaceship.h"
#include "trip.h"
#include "date_time.h"
#include <iostream>

class Driver:public User
{
public:
	Driver(std::string _user_name,std::string _password,std::string _spaceship_number,
	std::string _spaceship_model,
	std::string _production_year,
	std::string _color,Date_time* birth_date):User(_user_name,_password,"driver",birth_date){
		score=0;
		status="unavailable";
		is_accepted=false;
		model="driver";
		spaceship=new Spaceship(_spaceship_number,_spaceship_model,_production_year,_color);
	};
	std::string get_spaceship_number(){return spaceship->get_number();}
	std::string get_spaceship_model(){return spaceship->get_model();}
	std::string get_spaceship_color(){return spaceship->get_color();}
	void add_trip(Trip* new_trip){trips.push_back(new_trip);}
	std::string show_requests();
	std::string get_model(){return model;}
	int get_score(){return score;}
	void set_trip_rate(int rate);
	void erase_request(Trip* _trip);
	bool find_trip(Trip* _trip);
	void add_rate(int _rate){score+=_rate;} 
	virtual std::string show_information();
	void show_report(std::string from , std::string to);
	std::string get_username(){return user_name;}
	bool find_trip_for_accept();
	std::string get_driver_status(){return User::get_status();}
	~Driver();
	
protected:
	
	std::string model;
	std::vector<Trip*> trips;
	int score;
	Spaceship* spaceship;
};

#endif