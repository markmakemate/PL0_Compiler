#include<iostream>
#include<istream>
#include<fstream>
#include<vector>
#include<string>
#include "Keys.h"
class LexicalAnalysis{
    private:
    std::streambuf* buf;
    std::string candidate;
    std::vector<std::pair<std::string, std::string> > mediator;
    public:
    LexicalAnalysis(std::ifstream* ifs){
        std::streambuf* can_buf = ifs->rdbuf();
        do{
            if(can_buf->sgetc()>='A' && can_buf->sgetc()<='Z'){
                buf->sputc(can_buf->sgetc() + 32);
            } 
        }while(can_buf->snextc() != EOF);
        delete can_buf;
    }
    ~LexicalAnalysis(){
        delete buf;
    }
    void execute(){
        do{
            if(buf->sgetc() != '\0'){
                if(OperatorSet.find((int)buf->sgetc()) != OperatorSet.end()){
                    int op = IdentifyOperator();
                    if(OperatorsCodec.find(op) != OperatorsCodec.end()){
                        mediator.push_back(std::make_pair(candidate, OperatorsCodec[op]));
                    }else{
                        mediator.push_back(std::make_pair(candidate, "ERROR OPERATOR"));
                    }
                    
                }else if(MarginSet.find(buf->sgetc()) != MarginSet.end()){
                    if(IdentifyMargins()){
                        if(candidate.size() > 0){
                            IdentifyWord(candidate); 
                            candidate.clear();
                        }
                        mediator.push_back(std::make_pair(candidate, MarginsCodec[(int)buf->sgetc()]));
                    }else{
                        mediator.push_back(std::make_pair(candidate, "ERROR MARGIN"));
                    }
                }
            }else{
                IdentifyWord(candidate);
                candidate.clear();
            }
        }while(buf->snextc() != EOF);
    }
    //运算符识别器
    int IdentifyOperator(){
        do{
            candidate.push_back(buf->sgetc());
        }while(OperatorSet.find((int)buf->snextc()) != OperatorSet.end() && buf->sgetc() != EOF);
        char* op = new char[candidate.size()];
        int offset = 0;
        for(auto it = candidate.begin();it != candidate.end();it++){
            op[offset] = *it;
            offset++;
        }
        return std::atoi(op);
    }
    //界符识别器
    bool IdentifyMargins(){
        bool flag = true;
        candidate.clear();
        do{
            candidate.push_back(buf->sgetc());
            
        }while(MarginSet.find(buf->snextc()) != MarginSet.end() && buf->sgetc() != EOF);
        if(candidate.size() > 1){
            flag = false;
        }
        return flag;
    }
    //判断是否是常数
    bool IsConst(std::string& s){
        bool flag =true;
        for(auto it = s.begin();it != s.end();it++){
            if(*it >'9' && *it<'0'){
                flag = false;
            }
        }
        return flag;
    }
    //Getter方法
    std::vector<std::pair<std::string, std::string> > getMediator(){
        return mediator;
    }

    //非关键字、运算符和界符的字符识别器
    void IdentifyWord(std::string& s){
        if(ElementKeySet.find(s) != ElementKeySet.end()){
            mediator.push_back(std::make_pair(s, s + "sym"));
        }else if(IsConst(s)){
            mediator.push_back(std::make_pair(s, "number"));
        }else{
            mediator.push_back(std::make_pair(s, "ident"));
        }
    }
};