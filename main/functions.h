
#ifndef functions
#include <string>
#include <iostream>
using namespace std;
#define functions
    //initializing classes
    class bird_class{
	public:
		string name;
        void set_seen(int num){number_seen = num;}
		void increment_count(){number_seen++;} //methods are made inline by default, wow
        int get_count()const{return number_seen; } 
		explicit bird_class(string text, int seen = 0): name(text), number_seen(seen){} //constructor
        const bird_class &compare(const bird_class & other_bird);
        static string info(){return "Defines a bird a how many times it was seen.";}
        friend void display(bird_class bird);
        friend ostream &operator<<(ostream &stream, const bird_class & bird);
        friend istream &operator>>(istream &stream, const bird_class & bird);

        bird_class operator++(void);//overloading ++
        bird_class operator++(int);
        operator int() const;
        bird_class operator+(const bird_class & second_bird);//overloading +
        bird_class operator+(int n);
        friend int operator+(int n, bird_class &bird);

        void *operator new(size_t size);
        void operator delete(void *p);

        void *operator new[](size_t size);
        void operator delete[](void *p);
        friend class bird_watcher;
    private:
        int number_seen;
    };
    // bird_class::bird_class(string text){ //creating constructor
    //     name = text;
    //     number_seen = 0;
    // }
    //bird_class::bird_class(string text, int seen = 0): name(text), number_seen(seen){} 
    
    const bird_class & bird_class::compare(const bird_class &other_bird){
        if(get_count() > other_bird.get_count()){
            return *this; //dereferenced pointer to the object that is calling the method
        }
        else{return other_bird;}
    }
    const bird_class & compare_multiple(const bird_class other_bird[], int array_indexes){
        const bird_class *biggest_seen = &other_bird[0];
        for(int i = 1; i <= array_indexes; i++){
            if ((*biggest_seen).get_count() < other_bird[i].get_count()){
                biggest_seen = &other_bird[i];
            }
        }
        return *biggest_seen;
    }
    void display(bird_class bird){
        cout << "Bird's name is: " << bird.name << '\n';
        cout << "Bird's number seen: " << bird.number_seen << '\n';
    }
    bird_class bird_class::operator++(void){
        number_seen++;
        return *this; 
    }
    bird_class bird_class::operator++(int){
        number_seen++;
        return *this; 
    }
    bird_class::operator int() const{
        return number_seen;
    }
    bird_class bird_class::operator+(const bird_class & second_bird){
        bird_class temp("");
        temp.name = name + " and " +  second_bird.name;
        temp.set_seen(number_seen + second_bird.number_seen);
        return temp;
    }
    bird_class bird_class::operator+(int n){
        number_seen += n;
        return *this;
    }
    int operator+(int n, bird_class &bird){
        n += bird.get_count();
        return n;
    }
    ostream &operator<<(ostream &stream, const bird_class &bird){
        cout << "Number of " << bird.name << "s seen: " << bird.get_count() << '\n';
        return stream;
    }
    istream &operator>>(istream &stream, bird_class &bird){
        int num;
        cin >> bird.name >> num;
        bird.set_seen(num);
        return stream; 
    }
    void *bird_class::operator new(size_t size){
        cout << "Allocating memory..\n";
        void *p = new char[size];
        return p;
    }
    void bird_class::operator delete(void *p){
        cout << "Deleting memory...\n"; 
        delete[] (void *) p;
    }

    class bird_watcher{
        public:
            bird_watcher(string s){watcher_name = s;}
            int get_bird_number(bird_class &bird){
                return bird.number_seen;
            }
        private:
            string watcher_name;
    };

    class weirdo_watcher : public bird_watcher{
        public:
            weirdo_watcher(string s) : bird_watcher(s){cout << "Initializing name to " << s << '\n';}
            int get_bird_number(bird_class &bird){
                cout << "OOO ME BIRDY!";
                return bird.get_count();
            }
    };

    class great_person{
        public:
            void set_name(string text){name = text;}
            string get_name(){return name;}
            void set_age(int num){age = num;}
            void age_adder(){age++;} //real killer this one
            int get_age(){return age;}
            great_person(string name);
            virtual void speak(){cout << "Speaking...\n";}
            friend void display(const great_person& person){cout << "Name: " << person.name << "\n Age: " << person.age << '\n';}
            friend ostream &operator<<(ostream &stream, const great_person &person){
                cout << "Name: " << person.name << "\nAge: " << person.age << '\n';
                return stream;
            }
        private:
            int age;
            string name;
            string degree;
        protected:
            void breathe(){cout << "Breathing...\n";}
    };
    
   great_person::great_person(string name) : name(name), age(30){} //beautiful constructor, amazing.

   great_person & get_everything(great_person & object){ //dumbest shit ever
        object.set_name(object.get_name());
        object.set_age(object.get_age());
        return object;
   }
   class horrible_person : public great_person{
        public:
            void breathe(){great_person::breathe();}
            horrible_person(string name) : great_person(name){}
            void speak(){cout << "Horrible speaking...\n";}
   };

   class stack_class{
        public:
            stack_class(int mem_required);
            ~stack_class();
            int pop(int &pop_to);
            int push(int push_this);
            void stack_pusher(int index_num);
        private:
            int max_values;
            int *data_buffer;
            int stack_top; //When stack_top is -1, stack is empty
    };
    stack_class::stack_class(int mem_required){
        stack_top = -1;
        max_values = mem_required;
        data_buffer = new int[mem_required]; //Allocate memory
    }
    stack_class::~stack_class(){
        cout << "Deallocating memory. \n";
        delete[] data_buffer;
    }
    int stack_class::pop(int &pop_to){
        if (stack_top == -1){return 0;}
        else{
            pop_to = data_buffer[stack_top--];
            return 1;
        }
    }
    int stack_class::push(int push_this){
        if(stack_top >= max_values){return 0;} // Stack is full -- return error
        else{
            data_buffer[++stack_top] = push_this;
            return 1;
        }
    }
    void stack_class::stack_pusher(int index_num){
        int popped_value;
        for(int i = 0; i < index_num; i++){
            push(i);
            cout << "Pushed value: " << i << '\n';
        }
        cout << "Popping values... \n";
        while(pop(popped_value)){
            cout << "popped_value: " << popped_value << '\n';
        }
    }

    class Exception{
    public:
        explicit Exception(string s){name = s;}
        string get_name(){return name;}
    private:
        string name;
    };
    template <typename T>
    T arr_size(const T *arr){
        T i = 0;
        for(i; arr[i] != 0; i++){}; 
        return i;
    }



    //initializing structures
    struct person{
            string first_name;
            string last_name;
            int age;
        }plamp;

    
    //making anonymous struct
    struct{
        bool is_dog, is_cat;
        int age;
    }coquinha, cindy;
    //initializing struct
    struct is_truthful{
        bool is_true;
        bool is_false;
        double truh_per;
        double false_per;
    };
    

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
    long array_adder(const char array[], int number_elements);
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
    void adder_template(T &num, T num2);

    template <>  void adder_template(string &text, string text2);

    //testing inline function
    inline string printing_bogus(void){return "absolutely diabolical young lad!";}
    void references();
    person & returning_references(person & person_ref);
    int sizes_of_arrays(int arr[], int number_items);
    int sizes_of_arrays(char arr[], int number_items);
#endif