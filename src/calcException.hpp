#include <exception>


class CalcException : public std::exception{
    private:
        std::string msg;
    public:
        CalcException(const char* aMsg): msg(aMsg){};
        
        const char* what(){
            return msg.c_str();
        }

};