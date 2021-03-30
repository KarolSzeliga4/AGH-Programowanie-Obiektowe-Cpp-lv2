#pragma once
#include <iostream>
#include "TestClass.h"

class SmartPtr{
    public:
        SmartPtr(TestClass *A):ptr{A},counter{1}{;}
        //SmartPtr():ptr{nullptr},counter{0}{;}
        SmartPtr(SmartPtr &A){
            //delete ptr;
            ptr = A.getPtr();
            ++A.counter;
            counter = A.counter;
        }
        ~SmartPtr(){
            if(counter == 0){
                delete ptr;
            }
            
        }
        TestClass *getPtr() const{
            return ptr;
        }

        SmartPtr &operator=(SmartPtr &A){
            //--counter;
            if(counter == 1){
                delete ptr;
            }
            
            ptr = A.getPtr();
            ++A.counter;
            counter=A.counter;
            return *this;
        }

        TestClass *operator->() const{
            return ptr;
        }

        TestClass operator*() const{
            return *ptr;
        }

        int useCount() const{
            return counter;
        }
    private:
        TestClass *ptr;
        int counter;      
};