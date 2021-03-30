#pragma once 
#include<iostream>
#include "vector.h"
class Sapper;

namespace MyStuff {
class matrix;
}
std::ostream& operator<<(std::ostream &,const MyStuff::matrix &);

namespace MyStuff {

class matrix
{
public:
	friend std::ostream& ::operator<<(std::ostream& ,const MyStuff::matrix &);
	matrix();
	matrix(int,int);
	matrix(const matrix&);
	matrix(matrix&& );
	matrix& operator=(const matrix&);
	matrix& operator=(matrix&&);
	matrix operator+(const matrix&) const;
	matrix operator*(const matrix&) const;
	~matrix();
	vector& operator[](int) const;
	void fill(const vector*, int);
private:
	int _sizx;
	int _sizy;
	vector **_wskv;
};
}
