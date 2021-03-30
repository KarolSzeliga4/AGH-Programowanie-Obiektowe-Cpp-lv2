// Tutaj należy wpisać kod
#pragma once
#include "human.h"
#include<iostream>
#include<functional>
#include<vector>
using namespace std;

class Spacecraft{
    private:
        vector<Human*> po;
  public:
  		Spacecraft(vector<Human*>& l): po(l) {}
        Human& operator[](const string& a){
            for(auto C: po)
            	if(a == C->get_name())
            		return *C;
            cout << "\nThere is no name like: " << a << " on the ship\n";
            return *po[0];
        }
        void update_time(function< Time(Time) > f,const Time t){
        	for(auto C: po)
        		C->update_time(f(t));
        } 
};