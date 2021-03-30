// Tutaj proszę napisać klasę Rover
#pragma once
#include<iostream>

#include "utils.h"

using namespace std;



class Rover{
public:
    Rover(const char * s = "noname"): name(s), coordinates(), online(false){}
    Coordinates get_coordinates() const{ 
        return coordinates;
    }
    string get_name() const{
        return name;
    }
    void execute(const std::function< void() >& action_){
        if(online)
            action_();
        else
            cout<<"ERROR: Rover not linked to an interface.\n";
            
    }
	void drive(const Program& progr_){
	    if(online){
            for(unsigned int i =0; i< progr_.size(); i++){
                coordinates.dl += progr_[i]()[0];
                coordinates.sz += progr_[i]()[1];
            cout<<"Arriving at "<< coordinates<<endl;
            }
	    }
        else
            cout<<"ERROR: Rover not linked to an interface.\n";
	}
//protected:
    string name;
    Coordinates coordinates;
    bool online;
};