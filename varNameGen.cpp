#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//John Bedette, cs162
//a simple variable name generator


//consts
const int KEYWORDS = 41;
const int i = 0;

//prototypes
void welcome();
void inputKeywords(char[]);
void selectOutput(char[], char);
void removeSpaces(char[]);
void toUppercase(char[]);
void toLowercase(char[]);
void toCamelCase(char[]);
void toUnderscore(char[]);

//main
int main(){
    //variables
    char keywords[KEYWORDS];
    char option = ' ';
    
    //main flow
    welcome();
    inputKeywords(keywords);
    cout << ">>> " << keywords;
    selectOutput(keywords, option);
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
void selectOutput(char keywords[],char option){
    cout << "\n\n" << ">>> Please select an output option:" << '\n';
    cout << ">>> [L]owercase" << '\n';
    cout << ">>> [U]ppercase" << '\n';
    cout << ">>> [C]amelCase with the first letter capitalized" << '\n';
    cout << ">>> [R]egular CamelCase" << '\n';
    cout << ">>> [S]eparated by Underscores" << "\n\n";

    cin >> option;
    option = toupper(option);
    cin.ignore(100,'\n');

    if(option == 'L'){
        toLowercase(keywords);
        removeSpaces(keywords);
        cout << "\n\n" << ">>> Your varible name: " << keywords << "<<<" << '\n';
    }else if(option == 'C'){
        toCamelCase(keywords);
        removeSpaces(keywords);
        keywords[0] = toupper(keywords[0]);
        cout << "\n\n" << ">>> Your varible name: " << keywords << "<<<" << '\n';
    }else if(option == 'R'){
        toCamelCase(keywords);
        removeSpaces(keywords);
        keywords[0] = tolower(keywords[0]);
        cout << "\n\n" << ">>> Your varible name: " << keywords << "<<<" << '\n';
    }else if(option == 'S'){
        toUnderscore(keywords);
        toLowercase(keywords);
        cout << "\n\n" << ">>> Your varible name: " << keywords << "<<<" << '\n';
    }else if(option == 'U'){
        toUppercase(keywords);
        cout << "\n\n" << ">>> Your varible name: " << keywords << "<<<" << '\n';
    }else{
        //if the user doesn't pick anything this kicks you back to selection menu
        selectOutput(keywords, option); 
    }
}
//remove spaces in toUpper, toLower, toCamel
void removeSpaces(char keywords[]){ 
    int length = strlen(keywords);
    int i = 0;
    for(i = length; i > 0; --i){
       if (keywords[i] == ' '){
           int iTwo = i;
           for(i = iTwo; i < length; ++i){
               keywords[i] = keywords[(i+1)];
           } 
       }
    } 
}
//slice out spaces, then to upper
void toCamelCase(char keywords[]){
    int length = strlen(keywords);
    int i = 0;
    for(i = length; i > 0; --i){
        if(keywords[i] == ' '){
            keywords[(i+1)] = toupper(keywords[(i+1)]);
        }
    }
}
//slice out spaces, then to lower
void toLowercase(char keywords[]){
    int length = strlen(keywords);
    int i = 0;
    for(i = 0; i < length; ++i){
        keywords[i] = tolower(keywords[i]);
    }
}
//capitalize the entire word
void toUppercase(char keywords[]){
    int length = strlen(keywords);
    int i = 0;
    for(i = 0; i < length; ++i){
        keywords[i] = toupper(keywords[i]);
    }
}
//set to lower, then replace spaces w/underscores
void toUnderscore(char keywords[]){
    int length = strlen(keywords);
    int i = 0;
    for(i = length; i > 0; --i){
       if (keywords[i] == ' '){
            keywords[i] = '_';
       }
    } 
}
