#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//John Bedette, cs162
//a simple variable name generator


//consts
const int KEYWORDS = 41;

//prototypes
void welcome();
void inputKeywords(char[]);
void selectOutput(char[], char);
void removeSpaces(char[]);
void toUppercase(char[]);
void toLowercase(char[]);
void toCamelCase(char[]);
void toUnderscore(char[]);
void outputter(char[]);
void again();

//main
int main(){
    //variables
    char keywords[KEYWORDS];
    
    //input
    welcome();
    inputKeywords(keywords);
    again();
    return 0;
}
void again(){
    char option = ' ';
    cout << '\n' << ">>> If you would like to go again, please enter [y]." << "\n\n";
    cin >> option;
    cin.ignore(100,'\n');
    if(tolower(option) == 'y'){
        cout << '\n' << ">>> Restarting..." << "\n\n";
	main();
    }else{
        cout << '\n' << ">>> Goodbye" << "\n\n";
    }
}

void welcome(){
    cout << "\n\n" << ">>> Welcome to the variable name generator.";
    cout << "\n\n" << ">>> Please enter the keyword(s) you would like to implement." << "\n\n";
}

void inputKeywords(char keywords[]){
    char option = ' ';
    cin.get(keywords, KEYWORDS, '\n');
    cin.ignore(100,'\n');
    if(strlen(keywords) >= 3){
        cout << "\n\n" << ">>> Your keyword[s] are: " << keywords << '\n';
        selectOutput(keywords, option);
    }else{
        cout << "\n\n" << ">>> Please enter more than two letters" << '\n'; 
        inputKeywords(keywords);
    }
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
    }else if(option == 'C'){
        toCamelCase(keywords);
        removeSpaces(keywords);
        keywords[0] = toupper(keywords[0]);
    }else if(option == 'R'){
        toCamelCase(keywords);
        removeSpaces(keywords);
        keywords[0] = tolower(keywords[0]);
    }else if(option == 'S'){
        toUnderscore(keywords);
        toLowercase(keywords);
    }else if(option == 'U'){
        toUppercase(keywords);
    }else{
        //if the user doesn't pick anything this kicks you back to selection menu
        selectOutput(keywords, option); 
    }
    outputter(keywords);
}
void outputter(char keywords[]){
    int len = strlen(keywords);
    char theKeywords[KEYWORDS + 3];
    theKeywords[0] = 't';
    theKeywords[1] = 'h';
    theKeywords[2] = 'e';

    for(int i = 0; i < len; ++i){
        theKeywords[i+3] = keywords[i];
    } 

    cout << "\n\n" << ">>> Your varible names: " << keywords << " or "<< theKeywords << "<<<" << '\n'; 
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
