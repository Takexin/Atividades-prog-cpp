#include<iostream>
#include<string>
#include <vector>
using namespace std;
void fibonacci(){
    int sequence_num;
    string output;
    cout << "Type the number of the sequence: ";
    cin >> sequence_num;
    vector<int> fibo = {0, 1 };
    cout << fibo[0] << ", " << fibo[1] << ", ";
    for(int i = 2; i < sequence_num; i++){
        fibo.push_back(fibo[i-1] + fibo[i-2]);
        cout << fibo[i] << ", ";
    }
    cout << endl;
    
}

int main(){
    fibonacci();
    return 0;
}