#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//John Bedette, cs162
//a simple variable generator


//consts
int KEYWORDS = 41;

//prototypes
void welcome();
void inputKeywords(char[]);
void selectOutput(char[]);
void removeSpaces(char[]);
void toUppercase(char[]);
void toLowercase(char[]);
void toCamelcase(char[]);
void toUnderscore(char[]);

//main
int main(){
    //variables
    char keywords[KEYWORDS];
    
    //main flow
    welcome();
    inputKeywords(keywords);
    cout << ">>> " << keywords;
    selectOutput(keywords);
    return 0;
}

void welcome(){
    cout << "\n\n" << ">>> Welcome to the variable name generator.";
    cout << "\n\n" << ">>> Please enter the keyword(s) you would like to implement." << "\n\n";
}

void inputKeywords(char keywords[]){
    cin.get(keywords, KEYWORDS, '\n');
    cin.ignore(100,'\n');
}
//present user with menu and select string modification
void selectOutput(char keywords[]){
    char option = ' ';
    cout << "\n\n" << ">>> Please select an output option:" << '\n';
    cout << ">>> [L]owercase" << "\n";
    cout << ">>> [U]ppercase" << "\n";
    cout << ">>> [C]amelcase" << "\n";
    cout << ">>> [S]eparated by underscores" << "\n\n";

    cin >> option;
    option = toupper(option);
    cin.ignore(100,'\n');

    if(option == 'L'){
        toLowercase(keywords);
    }else if(option == 'U'){
        toUppercase(keywords);
    }else if(option == 'C'){
        toCamelcase(keywords);
    }else if(option == 'S'){
        toUnderscore(keywords);
    }else{
        //wonder how this works
       //selectOutput(option, keywords); 
    }
}
//remove spaces in toUpper, toLower, toCamel
void removeSpaces(char keywords[]){

}
//slice out spaces, then to upper
void toUppercase(char keywords[]){

}
//slice out spaces, then to lower
void toLowercase(char keywords[]){

}
//capitalize first letters of each word, then slice out spaces
void toCamelcase(char keywords[]){

}
//set to lower, then replace spaces w/underscores
void toUnderscore(char keywords[]){

}
