
#include "userheader.h"
#include "functions.h"
using namespace std;



//only use prototypes if the functions require arguments, wowies
int main(int argc, char *argv[]) {
	// caller_function("This hurts my brain", printem);
	// int value = 10;
	// cout << "I am going fucking crayz holy shit " << value << endl;
	// adder_ptr(&value, 1, 5);
	// cout << "value is now equal to: " << value << endl;
	// adder_reference(value);
	// cout << "this is using references: " << value << endl;
	// int number = 6;
	// int *ptr = &number;
	// caller_function(ptr, factorial);

	// //using template to adder
	// cout << '\n' << "adding numbers with templates" << endl;
	// double pi = 3.1415;
	// adder_template(pi, double(0.1234));
	// cout << "3.1415 + 0.1234 = " << pi << endl;

	// //using inline function test (placed in header file)
	// cout << printing_bogus() << endl;

	// //using default argument
	// cout << '\n' <<"Testing default argument:" << endl;
	// printem();

	// //using alias and references
	// cout << '\n' << "Testing alias and references: " << endl;
	// references();

	// //using references as argument and return value
	// cout << "Using references as argument and return value" << '\n';
	// person Dan = {
	// 	"Dan",
	// 	"The man",
	// 	50,
	// };
	// cout << "Current age of Dan: " << Dan.age << '\n';
	// returning_references(Dan);
	// cout << "Age of Dan after aditon: " << Dan.age << '\n';
	// returning_references(returning_references(Dan));
	// cout << "Age of dan after two consecutive additions: " << Dan.age << '\n'; 

	// //using static automatic variables in functions
	// cout << "Using static automatic variables in functions: " << '\n';

	// int array1[] = {3, 5, 6, 5, 67};
	// cout << "Number of elements in array1 = " << sizes_of_arrays(array1, 5) << '\n';

	// int array2[] = {3, 5, 9, 10};
	// cout << "Number of elements in array1 and array2 = " << sizes_of_arrays(array2, 4) << '\n';

	// //using specific template specializations
	// cout << "using specific template specializations: " << '\n';
	// string write_text = "Wus poppin";
	// adder_template(write_text, string("This is great")); 

	//Testing classes
	cout << "Testing classes, bird watching: " << '\n';
	cout << bird_class::info() << '\n';
	bird_class oriole("oriole");
	oriole.increment_count();
	cout << "Number of " << oriole.name << "s seen: " << oriole.get_count() << '\n' << '\n';

	bird_class eagle("eagle");
	eagle.set_seen(20);
	cout << "Which have I seen more between eagles and orioles: " << eagle.compare(oriole).name << '\n';
	cout << "Seen: " << eagle.compare(oriole).get_count() << " times \n";

	const bird_class birds[] = {bird_class(string("blue jay"), 5), bird_class(string("robin"), 3), bird_class(string("pidgeon"), 25), bird_class(string("amogus"), 125)};
	cout << "I have seen more " << compare_multiple(birds, 4).name << '\n';
	cout << "Seen: " << compare_multiple(birds, 4).get_count() << " times \n";

	bird_class *ptr_bird = ::new bird_class(string("Big man"), 69);//original new
	void (bird_class::*function_ptr)();//pointer to class method
	function_ptr = &bird_class::increment_count; 
	(ptr_bird->*function_ptr)();//calling pointer to method
	(eagle.*function_ptr)();//calling pointer to method
	int number_eagles = eagle;
	eagle++;
	(*ptr_bird)++; 
	cout << (*ptr_bird).get_count();
	display(*ptr_bird + eagle);
	display(eagle);
	display(eagle + 5);
	::delete ptr_bird;//original delete
	bird_class *bird_pointer = new bird_class("Over", 0);//overloaded new
	cout << *bird_pointer;

	delete bird_pointer;//overloaded delete
	int number_addition = 5 + eagle;
	cout << "Adding overloaded + with integers: 1" << number_addition << '\n';


	//testing custom class
	// cout << "Testing custom class (made by yours truly)" << '\n';
	// great_person jonathan("Jonathan");
	// great_person peter = string("peter"); //initializing object with one argument                         
	// cout << "This is " << jonathan.get_name() << ". He is " << jonathan.get_age() << " years old." << '\n';
	// jonathan.age_adder();
	// cout << "jonathan is magically " << jonathan.get_age() << " years old now" << '\n' << '\n';

	//Testing stack class
	// stack_class stack(200);
	// stack.stack_pusher(10);
	return 0;
}	
void bool_test(){
	bool is_true;
	cout << "If you want the boolean to be true, type '1': ";
	cin >> is_true;
	if(is_true){
		cout<< "oh, would you look at that. It's true! " << is_true << endl;
	}
	else if(!is_true){
		cout << "oh, what a shame, it is not true :( " << is_true << endl;
	}
}
void bit_sizes(){
	cout << "the char type is " << sizeof(char) << "byte long" << endl;
	cout << "the short type is " << sizeof(short) << "byte long" << endl;
	cout << "the int type is " << sizeof(int) << "byte long" << endl;
	cout << "the long type is " << sizeof(long) << "byte long" << endl;

}
void string_test(){
	string string1;
    cout << "Type a few words: ";

    getline(cin, string1);

    cout << "You typed: " << string1 << endl;

    cout << "Type a word: ";

    string1 = cin.get();
    cout << "The first character was: " << string1 << endl;
}
void const_test(){
	const int WEEK_DAYS = 7;
	int days = WEEK_DAYS;
	char test = 'a';
	cout << "There are " << days << " days in a week." << endl;
	cout << "The data type of week days is: " << (typeid(WEEK_DAYS).name(), 0, 0, 0) << endl;
}
void typeof_test(string input_var){
	cout << "The data type of this variable is: " << (typeid(input_var).name(), 0, 0, 0) << endl;
}
void type_cast_test(){
	// Example of an explicit type cast from a float to a pi, note that
	// the value of the variable itself does not change, it is casted
	// only for the expression.
	float pi = 3.141592;
	int num = 10;
	int sum = static_cast <int> (pi) + num;
	cout << "The type cast sum of pi into an int of 10 is: " << sum << endl;
}
void bitwise_unary_logical(){
	short number = 32767;
	bool boolean1 = true;
	cout << "Most negative short: " << ~number << '\n' << "!true = " << !boolean1 << endl;
}
void division_multiplication(){
	//division with integers truncates the result, use floats/doubles instead
	int int1 = 3, int2 = 10;
	cout << "10 / 3 = " << int2/int1 << endl; 
	cout << "10 * 3 = " << int2*int1 << endl;

}
void shifting(){
	int value = 16, negValue = -1;
	cout << value << " << 2 = " << (value << 2) << endl;
	cout << value << " >> 2 = " << (value >> 2) << endl;
	cout << negValue << " << 2 = " << (negValue << 2) << endl;
}
void ifThenElse(){
	unsigned int num1, num2, res;
	cout << "Digite o valor do primeiro numero: ";
	cin >> num1;
	cout << "Digite o valor do segundo numero: ";
	cin >> num2;
	if(num1 != num2){
	res = num1 > num2 ? num1 : num2;
	cout << "Maior numero: " << res << endl;
	}
	else{
		cout << "Os numeros devem ser diferentes!" << endl;
		ifThenElse();
	}
}
void roullete(){
	int num, ctrlNum;
	ctrlNum = rand() % 10 + 1;
	cout << "Type a number from 1 to 10 (choose carefully): ";
	cin >> num;
	if(ctrlNum != num){
		cout << "Hooray! Your computer lives." << endl;
	}
	else{
		system("death.exe");
	}
	
}
void random_number(){
	srand(time(0));
	double max;
	cout << "Type the limit of the random number: ";
	cin >> max;
	double res = ((static_cast <double> (rand())) / RAND_MAX) * max;
	cout << "Random number between 0 and " << max << " is: " << res << endl;
	cout << "seed: " << time(0) << endl;
}
string passed_grade(int score){
	if(score >= 60){
		return "Hooray!";
	}
	else{
		return "Aww, what a shame!";
	}
}
void arrays(){
	int scores[5];
	scores[0] = 55;
	scores[1] = 15;
	scores[2] = 20;
	scores[3] = 50;
	scores[4] = 74;
	scores[5] = 100;
	int other_scores[]  {55, 15, 20, 50, 74, 100};
	int* ptr = &scores[2];
	cout << "Person 3 got a grade of " << *ptr << " out of 100 " << 
	passed_grade(*ptr) << endl;
}
void multi_dimentional_arrays(){
	int scores[3][2] = {
		{0,0},
		{5,7},
		{3,2}
	};
	//bidimensional arrays are row -> column, be careful!
	float sum;
	int b;
	for(int i = 0; i < 3; i++){
		for(b = 0, sum = 0; b< 2; b++){
			sum = sum + scores[i][b];
		}
		cout << "Average for student " << i + 1 << " is " << sum/2 << endl; 
	}
}

void arrays_tet(){
	int test_index, student_index, scores[3][5] = {
		{92, 73, 57, 98, 89},
		{88, 76, 23, 95, 72},
		{94, 82, 63, 99, 84}
	};
	float sum;
	for(test_index = 0; student_index < 3; test_index++){
		for(student_index = 0, sum = 0; student_index < 5; student_index++){
			sum = sum + scores[test_index][student_index];
		}
		cout << "Average for test" << test_index++ << " is " << sum/5 << endl;
	}
}
void StyleCString(){
	char word[] = "HELLO";
	cout << word << endl;
}

void person_struct_test(){
	person ralph;
	person alice;

	ralph.first_name = "Ralph";
	ralph.last_name = "Kranken";
	ralph.age = 69;
	cout << "The first person is " << ralph.first_name <<
	" " << ralph.last_name << ", age " << ralph.age << endl;

	coquinha.is_cat = true;
	coquinha.is_dog = false;
	cindy.is_cat = false;
	cindy.is_dog = true;

	is_truthful isnt = {false, true, 0, 20};
	//assigning structure to another structure
	is_truthful isnt_question_mark = isnt;
	cout << "Is it true? " << isnt.is_true << endl;
	typedef bool i_want_to_die;
	i_want_to_die sleepy = true;
}

union one_union{
		double double_var;
		double double_var2;
	};
void union_test(){
	one_union union1;
	union1.double_var = 340;
	cout << "double_var = " << union1.double_var << endl;
	cout << "double_var2 = " << union1.double_var2 << endl; 
}
enum day{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};
void enum_test(){
	enum day today;
	int num;
	cout << "Type the day of the week: ";
	cin >> num;
	today = static_cast <day> (num);
	cout << static_cast <day> (today) << endl;	
	if (today == Sunday){
		cout << "Today is Sunday!" << endl;
		
	}
	else if (today == Monday){
		cout << "Today is Monday!" << endl;
	}
	else if (today == Tuesday){
		cout << "Today is Tuesday!" << endl;
	}
	else if (today == Wednesday){
		cout << "Today is Wdnesday!" << endl;
	}
	else if (today == Thursday){
		cout << "Today is Thursday!" << endl;
	}
	else if (today == Friday){
		cout << "Today is Friday!" << endl;
	}
	else if (today == Saturday){
		cout << "Today is Saturday!" << endl;
	}
	else{
		cout << "Please enter a valid day" << endl;
	}
	enum_test();
}

void pointer2ptr(){
	int integer = 1, *pointer, **pointer2;
	pointer = &integer;
	pointer2 = &pointer;
	cout << **pointer2 << endl;
}
void pointer_arrays(){
	double arr[5] = {0.5, 0.69, 1.23, 3.14, 5.55};
	double *pointer = arr;
	cout << "*pointer = " << *pointer << endl;
	cout << "*(++pointer) = " << pointer[1] << endl; //or *(++pointer) 
}
void delete_pointer_array(){
	double *values = new double[10];
	if(values == NULL)exit(1);
	values[5] = 3.14159;

	cout << "Stored value: " << values[5] << endl;
	cout << "Also stored value: " << *(values + 5) << endl;
	delete[] values; 
}
void multi_dimensioned_array_pointer(){
	float (*pointer)[200][300];
	pointer = new float[100][200][300];
	delete[	] pointer;
}
void pointers_to_cstyle_strings(){
	const char *message = "This points to a c-style string!";
	cout << message << endl;

	char string1[] = "We are building a house!";
	char string2[] = "ing";
	char *string3;
	string3 = strstr(string1,string2);
	cout << string3 << endl;

	char word1[] = "Wassup";
	char word2[] = " brotha";
	char *word3;
	word3 = strcat(word1,word2);
	cout << word3 << endl;

	person *pointer = &plamp;
	pointer->age = 10;
	pointer->first_name = "Clamp";
	(*pointer).last_name = "Robertson";
	cout << plamp.first_name << endl;
	cout << (*pointer).last_name << endl;

}

struct structure{
	int integer1;
	int integer2;
	struct structure *next;
}structure1, structure2, structure3;
void struct_pointer_linked(){
	structure1.next = &structure2; //setup linked list
	structure2.next = &structure3;

	structure2.integer1 = 5;
	//accessing the value of integer1 through the first structure
	cout << "Value of integer1 of structure2 = " <<structure1.next->integer1 << endl;
}
/* AUTO_PTR IS DEPRECATED
void auto_pointers(){
	auto_ptr<string> pointer (new string ("Hello from automatically deleted pointer!"));
	cout << *pointer << endl;
}
*/

void const_pointer_rules(){
	//Way 1 of using constant pointers
	int integer1 = 5;
	const int *pointer1 = &integer1;
	//Way 2
	const int integer2 = 5;
	const int *pointer2 = &integer2;
	//Way3
	const int integer3 = 5; //or int integer3 = 5;
	const int * const pointer3 = &integer3;
	//Incorrect way
	/*
	const int integer3 = 5;
	int *pointer3 = &integer3;
	*/
}
void casting_pointers(){
	int integer = 5;
	void *pointer = &integer;
	cout << "The value of the integer is " << *(static_cast <int * > (pointer)) << endl;

	//casting away constness
	char *ptr;
	const char *const_ptr;
	ptr = const_cast <char *> (const_ptr);

	//using reinterpret cast (most powerful) to set an address directly to a pointer
	pointer = reinterpret_cast<int *> (0xb0000000);
}
void command_lines(int argc, char * argv[]){
	for(int i = 0; i < argc; i++){
		cout << *(argv + i) << endl;
	}
}
long array_adder(const int array[], int number_elements)
//declared aray as constant since its a constant pointer,
//might change values in array
{ 
	static long sum = 0;
	for(int i=0; i < number_elements; i++){
		sum = sum + *(array + i); // used pointer notation
	}
	return sum;
}
long array_adder(const char array[], int number_elements)
//declared aray as constant since its a constant pointer,
//might change values in array
{ 
	static long sum = 0;
	for(int i=0; i < number_elements; i++){
		sum = sum + *(array + i); // used pointer notation
	}
	return sum;
}
void print_string(const char *text){
	cout << text << endl;
}
char* return_greeting(){
		char message[] = "What is up, brotha";
        char *text = new char[strlen(message) + 1];
        strcpy(text, "What is up, brotha");
        return text;
}
void factorial(int *value, int num){
	cout << "initial value of num: " << num << endl;
	if((*value) != 1){
		num = (num * ((*value)-1));
		*value = *value - 1;
		cout << "num = " << num << endl;
		cout << "value: "<< *value << endl; 
		factorial(value, num);
		
	}
}
void printem(string text){
	cout << text << endl;
}
void caller_function(string text, void(*pointer_to_function)(string)){
	(*pointer_to_function)(text);
}
void caller_function(int *value, void(*pointer_to_function)(int*, int)){ //function overloading, i am a fucking genious
	(*pointer_to_function)(value,*value);
}
void adder_ptr(int *num, int num_add,int repetition){
	if(repetition != 0){
		(*num) = (*num) + num_add;
		repetition --;
		adder_ptr(num, num_add, repetition);
	}
}
void adder_reference(int & num){
	num = num + 100;
}

void print_this(int value){cout << value<< endl;}

template <typename T>
void adder_template(T &num, T num2){
	num += num2;
}
template <> void adder_template(string &text, string text2){
	cout << "Sorry pal, you cannot do that!" << '\n';
	cout << "'" << text << "'" << " and " << "'"<<text2 <<"'" << " are not defined." << '\n';
}
void references(){
	int couches = 100;
	int & sofas = couches;

	cout << "Address of couches: " << &couches << endl;
	cout << "Address of sofas: " << &sofas << endl;

	cout << "Number of couches: " << couches << endl;
	cout << "Number of sofas: " << sofas << endl;

	couches++;
	cout << "Number of couches: " << couches << endl;
	cout << "Number of sofas: " << sofas << endl;
}

person & returning_references(person & person_ref){
	person_ref.age++;
	return person_ref;
}

int sizes_of_arrays(int arr[], int number_items){
	static int sum = 0;
	for(int i=0; i < number_items; i++){sum++;}
	return sum;
}
int sizes_of_arrays(char arr[], int number_items){
	static int sum = 0;
	for(int i=0; i < number_items; i++){sum++;}
	return sum;
}

