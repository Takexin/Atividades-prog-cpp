#include<iostream>
#include <cstring>
#include <string>
using namespace std;
void print_this(char character){cout << character << endl;}
void print_this(string text){cout << text << endl;}
void print_this(char *c_string){cout << c_string << endl;}
void print_this(int ascii){cout << static_cast <char> (ascii) << endl;}

int main(){
    print_this('a');
    print_this(string("This is pretty sick!"));
    print_this(92);
    char message[] = "currently using c-style string!";
    char *text = new char[(strlen(message) + 1)];
    strcpy(text, "currently using c-style string!");
    print_this(text);
    delete text;
    return 0;
}