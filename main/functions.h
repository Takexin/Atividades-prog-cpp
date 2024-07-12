
#ifndef functions
#include <string>
#include <iostream>
using namespace std;
#define functions
    void bool_test();
    void bit_sizes();
    void string_test();
    void const_test();
    void typeof_test();
    void type_cast_test();
    void bitwise_unary_logical();
    void division_multiplication();
    void shifting();
    void ifThenElse();
    void roullete();
    void passed_grade();
    void random_number();    
    void arrays();
    void multi_dimensional_arrays();
    void arrays_test();
    void StyleCString();
    void person_struct_test();
    void union_test();
    void enum_test();
    void pointer2ptr();
    void pointer_arrays();
    void delete_pointer_array();
    void multi_dimensioned_array_pointer();
    void pointer_to_cstyle_strings();
    void struct_pointer_linked();
    // AUTOPOINTER IS DEPRECATED void auto_pointer();
    void const_pointer_rules();
    void casting_pointers();
    void command_lines();
    long array_adder(const int array[], int number_elements);
    void print_string(const char *text);
    char* return_greeting();
    void factorial(int *value, int num );
    void printem(string text = string("OI! You didn't put shit in this!"));
    void caller_function(string text, void (*pointer_to_function)(string));
    void caller_function(int *value, void(*pointer_to_function)(int*, int));
    void adder_ptr(int *num, int num_add,int repetition);
    void adder_reference(int & num);
    void print_this(int value);
    template <typename T>
    T adder_template(T &num, T num2);
    //testing inline function
    inline string printing_bogus(void){return "absolutely diabolical young lad!";}
    void references();
#endif