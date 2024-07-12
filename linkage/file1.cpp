#include <iostream>
using namespace std;

int var1 = 5;

void second_file_declaration();
int main(){
    cout << "In file 1..." << endl;
    cout << "var1 = " << var1 << endl;

    second_file_declaration();
    return 0;
}