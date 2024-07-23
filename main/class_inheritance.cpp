#include <iostream>
#include "functions.h"
#include <typeinfo>

template <class T, int default_value>//class templates
class Array{
private:
    T *pointer_to_array;
    int number;
public:
    explicit Array(int number_of_elemets){
        string str = typeid(T).name();
        if(str.find("string") != string::npos){
            number = number_of_elemets;
            pointer_to_array = new T[number];
            for(int i = 0; i < number; i++){
                pointer_to_array[i] = default_value;//did not let me use pointer notation, crying
            }
        }
        else{
            throw Exception(string("Error:  used string as item value"));
        }
        
    }
    Array(const Array &arr){//copy constructor (since were using pointers)
        number = arr.number;
        T *pointer_to_array = new T[number];

        for(int i = 0; i < number; i++){
            (*pointer_to_array) + i = arr[i];
        }
    }
    ~Array(){
        delete[] pointer_to_array;
        cout << "Deleting array...";
    }
    T&operator[](int index){return pointer_to_array[index];}
    friend void display(Array &arr, int index){
        cout << "Student " << index << " scored " << arr[index] << " points \n";
    }
    T &operator=(const Array &arr){
        if(this == arr){
            return *this;
            delete[] pointer_to_array;
        }
        number = arr.number;
        T *pointer_to_array = new T[number];
         for(int i = 0; i < number; i++){
            (*pointer_to_array) + i = arr[i];
        }
        return *this;
    }
};


int main(){
    bird_class oriole(string("Oriole"), 23);
    weirdo_watcher jonathan(string("Jonathan"));
    cout << jonathan.get_bird_number(oriole) << '\n';
    great_person pat(string("Patterson"));
    great_person *pointer;
    pointer = &pat;
    pointer->speak();
    horrible_person jason(string("Jason"));
    pointer = &jason;
    pointer->speak(); 
    horrible_person *bad_pointer = &jason;
    bad_pointer->breathe();

    const int student_number = 5;
    Array <int, 0> scores(10);
    scores[0] = 3;
    scores[1] = 3;
    scores[2] = 3;
    scores[3] = 3;
    scores[4] = 3;
    scores[student_number] = 85;
    display(scores, student_number);
    display(scores, 1);
    int array[6] = {3, 6, 8, 1 ,5, 6};
    const int *ptr = &scores[0];
    cout << arr_size(ptr) << '\n';

    try{
        Array <string, 5> fail(5);
    }
    catch (Exception e){
        cout << e.get_name() << '\n';
    }
    return 0;
}