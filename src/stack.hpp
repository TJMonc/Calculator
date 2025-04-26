#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Stack{
    private:
        std::string* stack;
        int m_size;
        int capacity;
    public:
        Stack();

        void push(std::string val);
        std::string pop();

       inline int size(){return this->m_size;};

       inline ~Stack() { delete[] stack; };

       inline std::string peek(){return stack[m_size - 1];};

        std::string& operator[](int index){
            if(index >= m_size){
                throw 1;
            }
            return stack[index];
        }
}; 