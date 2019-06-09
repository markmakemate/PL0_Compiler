#include<iostream>
#include<istream>
#include<fstream>
#include<vector>
#define MARGIN_ERROR "ERROR MARGIN"
class Parser{
    private:
    std::vector<std::pair<std::string, std::string> >* data;
    public:
    Parser(std::vector<std::pair<std::string, std::string> >& mediator){
        data = &mediator;
    }
    ~Parser(){
        
    }
    void FIRST(){

    }
    void FOLLOW(){

    }
    

};