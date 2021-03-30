#pragma once
#include <iostream>
//#include <string>

class TestClass {
public:
	TestClass(std::string nazwa) :name{ nazwa } { 
		std::cout << "++ Tworze obiekt TestClass: " << name << std::endl;
	}
	~TestClass() {
		std::cout << "-- Usuwam obiekt TestClass: " << name << std::endl;
	}

	std::string info() const{
		return name;
	}

	void set_name(const std::string a){
		name = a;
	}

private:
	std::string name;

};