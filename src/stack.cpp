#include "stack.hpp"

Stack::Stack(){
    m_size = 0;
    capacity = 10;

    stack = new std::string[capacity];
}

void Stack::push(std::string val) {
    if(m_size >= capacity){
        capacity *= 2;
        std::string* newStack = new std::string[capacity];

        for(int i = 0; i < m_size; i++){
            newStack[i] = stack[i];
        }

        delete[] stack;
        stack = nullptr;

        stack = newStack;
    }

    stack[m_size] = val;
    m_size++;
}

std::string Stack::pop(){
    if(m_size <= 0){
        std::cout << "Stack empty\n";
        return "-1";
    }
    std::string temp = stack[m_size - 1];
    m_size--;

    return temp;
}
