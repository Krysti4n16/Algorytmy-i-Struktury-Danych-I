#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include <cassert>


int ONP(const std::vector<std::string>& input){
    std::stack<int> stos;
    std::string token;
    
    for(const auto& token : input){
        if(token== "+" || token== "-" || token== "*" || token== "/"){
            if(stos.size()<2){
                //std::cout << "Za malo argumentow dla operatora " << token << std::endl;
                return -1;
            }
            int a,b;
            b= stos.top();
            stos.pop();
            a= stos.top();
            stos.pop();

            int w;
            switch(token[0]){
                case '+':
                    w=a+b;
                    break;
                case '-':
                    w=a-b;
                    break;
                case '*':
                    w=a*b;
                    break;
                case '/':
                    if(b==0){
                        //std::cout << "nie mozna dzielic przez zero" << std::endl;
                        return -1;
                    }
                    w=a/b;
                    break;
                default:
                    //std::cout << "nieprawidlowy operator." << std::endl;
                    return -1;
            }
            stos.push(w);
        }
        else{
            int x;
            x=stoi(token);
            stos.push(x);
        }

    }
    if(stos.size()==1){
        return stos.top();
    } 
    else{
        //std::cout << "Za duzo wartosci na stosie" << std::endl;
        return -1;
    }
}

void testONP(){

    std::cout << "Test ONP..." << std::endl;
    
    std::vector<std::string> input1 { "2", "3", "+" };
    assert(ONP(input1) == 5);

    std::vector<std::string> input2 { "10", "4", "-" };
    assert(ONP(input2) == 6);

    std::vector<std::string> input3 { "7", "8", "*" };
    assert(ONP(input3) == 56);

    std::vector<std::string> input4 { "9", "3", "/" };
    assert(ONP(input4) == 3);

    //dzielenie przez zero
    std::vector<std::string> input5 { "10", "0", "/" };
    assert(ONP(input5) == -1);

    //zbyt malo argumentow
    std::vector<std::string> input6 { "+" };
    assert(ONP(input6) == -1);

    //zbyt wiele liczb
    std::vector<std::string> input7 { "3", "4", "5", "+" };
    assert(ONP(input7) == -1);

    std::vector<std::string> input8 { "-6", "2", "+" };
    assert(ONP(input8) == -4);

    std::vector<std::string> input9 { "12", "2", "3", "4", "*", "10", "5", "/", "+", "*", "+"};
    assert(ONP(input9) == 40);

    std::cout << "Testy zakonczone pomyslnie" << std::endl;
}

int main(){
    testONP();
    return 0;
}
