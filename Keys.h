#include<map>
#include<string>
#include<set>
using namespace std;

map<int, string> OperatorsCodec = {
    {(int)'+', "plus"}, {(int)'-', "minus"},{(int)'*',"times"},{(int)'/', "slash"},{(int)'=', "eql"},{(int)'|', "or"},
    {(int)'#', "neq"}, {(int)'<', "lss"}, {atoi("<="), "leq"}, {'>', "gtr"}, {atoi(">="), "geq"}, {atoi(":="), "becomes"}
};
map<int, string> MarginsCodec = {
    {(int)')', "lparen"}, {(int)'(', "rparen"}, {(int)',', "comma"}, {(int)';', "semicolon"}, {(int)'.', "period"}
};

set<int> OperatorSet = {(int)'+', (int)'-', (int)'*', (int)'/', (int)'=', (int)'#', (int)'<', atoi("<="), '>', atoi(">="), atoi(":="), (int)'|'};

set<string> ElementKeySet = {"begin", "call", "const", "do", "end", "if", "odd", "procudure", "read", "then", "var", "while", "write", "else"};

set<int> MarginSet = {(int)')', (int)'(', (int)',', (int)';', (int)'.'};
