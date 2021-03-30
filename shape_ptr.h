#pragma once
#include "shape.h"

class Shape_ptr{
public:
    Shape_ptr(): ptr(nullptr){}
    Shape_ptr(Shape* p): ptr(p){}//std::cout<<"błąd!\n";}
    Shape_ptr(const Shape_ptr& A) = delete;
    // {
    //     std::cout<<"błąd! nie można kopiować mądrego wskaźnika!\n";
    //     ptr = A.ptr;
    //     A.ptr = nullptr;
    // }
    ~Shape_ptr(){ if(ptr) delete ptr;}
    Shape&  operator*()const {return *ptr;}
    operator bool()const {
        if(ptr ==nullptr) 
            return false; 
        else 
            return true;
    }
    operator Shape*(){return ptr;}
    
    Shape_ptr& operator=( Shape*& A){
        if(ptr == A) return *this;
        
        if(ptr)
            delete ptr;
            
        ptr = A;
        A = nullptr;
        return *this;
    }
    Shape_ptr& operator=( Shape_ptr& A){
        if(ptr == A.ptr) return *this;
        
        ptr = A.ptr;
        A.ptr = nullptr;
        return *this;
    }
 private:
    Shape* ptr;
};