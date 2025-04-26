#include "calc.hpp"


int main(int argc, char**argv){
    std::vector<std::string> stack;
    while(true){
        std::string val;
        std::cin >> val;
        if(val == "="){
            break;
        }
        if(val.find_first_not_of("1234567890-+*/^()=") != std::string::npos){
            std::cout << "ERROR: Invalid term\n";
            std::cin.get();

            return -1;
        }

       stack.push_back(val);
    }
    std::cin.ignore(1);

    Calculator calc(stack);
    try{
        double answer = calc.calculate();
        std::cout << "Answer: " << answer;
    }
    catch(CalcException& e){
        std::cout << "ERROR: " << e.what();
    }

    std::cin.get();
}