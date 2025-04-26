#pragma once

#include "stack.hpp"


class Calculator{
    
    private:
        Stack stack;
        Stack evalStack;
        std::string infixStr;
        std::string postFixStr;
        std::vector<std::string> infixVect;
        std::vector<std::string> postfixVect;

        double operands[2];
        double result;
        double answer;
    public:
        static const std::unordered_map<std::string, int> operatorMap;
    private:
        int findType(std::string s);

        std::vector<std::string> infixToPostFix();

        double evaluate();
    public:
        Calculator(std::vector<std::string>& infix);
        double calculate();
};
