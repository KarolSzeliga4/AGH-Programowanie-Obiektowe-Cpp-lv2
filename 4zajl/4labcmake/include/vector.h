#pragma once 
#include<iostream>

namespace MyStuff {
class vector;
}
	std::ostream& operator<<(std::ostream &,const MyStuff::vector &);

namespace MyStuff {
class vector { 
public: 
		friend std::ostream & ::operator<<(std::ostream &,const MyStuff::vector &);
		vector();
		vector(int );
		vector(const vector &); 
		vector(vector &&);
		~vector();
		int& operator[](int ) const;
		int size() const;
		vector& operator=(const vector&);
		vector& operator=(vector &&);
        vector operator+(const vector&) const;
        void push_back(int ); 
        void pop_back(int ); 
private:
	int siz;
	int *tab;
};
}
