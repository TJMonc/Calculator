#include "stack.hpp"


int main(int argc, char**argv){
    Stack stack;
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

       stack.push(val);
    }
    std::cin.ignore(1);
    int size = stack.size();
    for(int i = 0; i < size; i++){
        std::cout << stack.pop() << " ";
    }

    std::cin.get();
}