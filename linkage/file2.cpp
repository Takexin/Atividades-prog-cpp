#include <iostream>
using namespace std;

extern int var1;
void second_file_declaration(){
    cout << "in the second file..." << endl;
    cout << "var1 = " << var1 << endl;
}