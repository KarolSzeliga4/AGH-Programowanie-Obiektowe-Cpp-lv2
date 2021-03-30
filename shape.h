#pragma once
#include<vector>
#include<iostream>
//using namespace std;

class Shape {
public:
    friend std::ostream& operator<<(std::ostream& out, const Shape&); 
    Shape(const char* n, std::vector<double> p): name(n), param(p){}
    virtual ~Shape(){}
    virtual double area()const =0 ;
    virtual double circumference()const =0;
protected:
    std::string name;
    std::vector<double> param;
};

std::ostream& operator<<(std::ostream& out, const Shape& A){
    out<<A.name;
    return out;
}

class Circle : public Shape{
public:
    using Shape::Shape;
    ~Circle(){}
    double area() const{ return 3.14*param[0]*param[0];}
    double circumference() const{ return 2.*3.14*param[0];}
};

class Rectangle : public Shape{
public:
    using Shape::Shape;
    ~Rectangle(){}
    double area() const{ return param[0]*param[1];}
    double circumference() const{ return 2.*param[0] + 2.*param[1];}
};