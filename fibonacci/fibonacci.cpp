#include<iostream>
#include<string>
using namespace std;
void fibonacci(){
    int sequence_num;
    string output;
    cout << "Type the number of the sequence: ";
    cin >> sequence_num;
    long long int fibo[sequence_num-1] = {0, 1};
    cout << fibo[0] << ", " << fibo[1] << ", ";
    for(int i = 2; i < sequence_num; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        cout << fibo[i] << ", ";
    }
    cout << endl;
    
}

int main(){
    fibonacci();
    return 0;
}