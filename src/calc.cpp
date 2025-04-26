#include "calc.hpp"

const std::unordered_map<std::string, int> Calculator::operatorMap = {
    {"+", 0},
    {"-", 0},
    {"*", 1},
    {"/", 1},
    {"^", 2},
    {"(", 3},
    {")", -1}
};

int Calculator::findType(std::string s) {
    if(s == ""){
        throw CalcException("Formatted incorrectly");
    }

    if(s.find_first_not_of("1234567890-.") == std::string::npos){
        return 0;
    }
    else if(s.find_first_not_of("+-*/^()") == std::string::npos){
        return 1;
    }
    else{
        throw CalcException("Could not parse user input.");
    }
}

std::vector<std::string> Calculator::infixToPostFix() {
    for(int i = 0; i < infixVect.size(); i++){
        std::string s = infixVect.at(i);

        if(s == ")"){
            while(stack.peek() != "(" || stack.peek() == ""){
                postfixVect.emplace_back(stack.pop());
            }
            if(stack.peek() == "("){
                stack.pop();
            }
        }

        else if(findType(s) == 0){
            postfixVect.emplace_back(s);
        }
        else{
            if(stack.peek() == "" || operatorMap.at(s) > operatorMap.at(stack.peek()) || stack.contains("(")){
                stack.push(s);
            }
            else{
                while(stack.peek() != "" && operatorMap.at(s) <= operatorMap.at(stack.peek())){
                    postfixVect.emplace_back(stack.pop());
                }
                stack.push(s);
            }

        }
    }
    while(stack.peek() != ""){
        postfixVect.emplace_back(stack.pop());
    }
    
    return postfixVect;
}

double Calculator::evaluate(){
    for(int i = 0; i < postfixVect.size(); i++){
        auto& element = postfixVect.at(i);

        if(findType(element) == 0){
            evalStack.push(element);
        }
        else{
            operands[1] = std::stod(evalStack.pop());
            operands[0] = std::stod(evalStack.pop());

            char op = element[0];

            switch(op){
                case '+':
                    result = operands[0] + operands[1];
                    break;
                case '-':
                    result = operands[0] - operands[1];
                    break;
                case '*':
                    result = operands[0] * operands[1];
                    break;
                case '/':
                    result = operands[0] / operands[1];
                    break;
                case '^':
                    result = std::pow(operands[0], operands[1]);
                    break;
                default:
                    throw CalcException("Couldn't parse bs");
                    break;
            }
            evalStack.push(std::to_string(result));
        }
    }
    answer = std::stod(evalStack.peek());

    return answer;
}

Calculator::Calculator(std::vector<std::string> &infix):
infixVect(infix)
{

}
double Calculator::calculate()
{
    infixToPostFix();
    evaluate();
    return answer;
};
