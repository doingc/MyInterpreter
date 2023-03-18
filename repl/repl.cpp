#include "repl.h"
#include <algorithm>
#include <exception>
#include <iostream>

using namespace std;

void print_anthor_name();

void print_parser_errors(vector<string> errors);

void Repl::start() {

    print_anthor_name();

    const string PROMPT = ">>>>> ";

    std::string line;
    parser p ;
    while (1) {
        cout << PROMPT;
        getline(cin, line);
        parser par(line);
        par.New(line);
        while(true){
            token* t = par.NextToken();
            if(t->type == token::E0F){
                break;
            }else{
                std::cout<<"type: "<<t->type<<"token literal:"<<t->literal<<std::endl;
            }
        }


/**/
    }
}

void print_anthor_name() {
    string name = R"(
	########################
             -    -
              哈哈哈
	########################
)";

    cout << name << endl;
}

void print_parser_errors(vector<string> errors) {
    print_anthor_name();
    cout << "Woops! We ran into some `mirror` business here!\n";
    cout << " parser errors:\n";
    for (int i = 0; i < errors.size(); i++) {
        cout << "\t" << errors[i] << endl;
    }
}