#include "userheader"
using namespace std;
using namespace abi;

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
	cout << "The data type of week days is: " << __cxa_demangle(typeid(WEEK_DAYS).name(), 0, 0, 0) << endl;
}
void typeof_test(string input_var){
	cout << "The data type of this variable is: " << __cxa_demangle(typeid(input_var).name(), 0, 0, 0) << endl;
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
struct person{
		string first_name;
		string last_name;
		int age;
	};

void person_struct_test(){
	person ralph;
	person alice;

	ralph.first_name = "Ralph";
	ralph.last_name = "Kranken";
	ralph.age = 69;
	cout << "The first person is " << ralph.first_name <<
	" " << ralph.last_name << ", age " << ralph.age << endl;
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
void switch_case_test(){
	day today = Thursday;
	switch(today){
		case Sunday:
			cout << "Today is Sunday!" << endl;
			break;
		case Monday:
			cout << "Today is Monday!" << endl;
			break;
		case Tuesday:
			cout << "Today is Tuesday!" << endl;
			break;
		case Wednesday:
			cout << "Today is Wednesday!" << endl;
			break;
		case Thursday:
			cout << "Today is Thursday!" << endl;
			break;
		case Friday:
			cout << "Today is Friday!" << endl;
			break;
		case Saturday:
			cout << "Today is Saturday!" << endl;
			break;
	}
}
void dowhile_test(){
	long num;
	int i = 0;
	cout << "Type a number: ";
	cin >> num;
	do{
		cout << "Wow, index of: " << i << endl;
		i++;
	}while(i<num);
}
void continue_test(){
	//division by itlsef - avoiding 0/0
	long iWantToDie;
	cout << "Type number to do the division: ";
	cin >> iWantToDie;
	for(iWantToDie; iWantToDie > -4; iWantToDie--){
		if(!iWantToDie) continue;
		cout << iWantToDie << "/" << iWantToDie << " = " << iWantToDie/iWantToDie << endl;
					
	}

}
void goto_test(){
	int number;
	cout << "Division of number by other numbers" << endl;
	cout << "Type the number: ";
	cin >>	number;
	for(int i=number; i>=0; i--){
		if(i == 0) goto END_LOOP;
		cout << number << " / " << i << " = " << number/i;
	}
	exit(0);
	END_LOOP: cerr << "Ending loop to avoid dividing by 0";
}
void pointer_adresses(){
	int bananas = 10;
	int oranges = 20;
	cout << "I have " << bananas << " Bananas at the address " << &bananas << endl;
	cout << "I have " << oranges << " Oranges at the address " << &oranges << endl;

	int integer, *pointer;

	integer = 1;
	pointer = &integer;

	int integer2 = 2, *const pointer2 = &integer2;

	//changing integer's data
	*pointer = 2;

	cout << "The value of the integer is: " << *pointer << endl;
}
void dynamic_memory_storage(){
	double *pi = new double;
	//checking if the program could not allocate memory for the pointer
	if(*pi == NULL)exit(1);
	*pi = 3.14159;
	cout << "The value of pi = " << *pi << endl;

	delete pi;
}
void pointer_arithmetic(){
	double values[4] = {0.1, 1.1234, 2.2, 3.5};
	double *pointer = &values[0]; //same thing as double *pointer = values;
	for(int i = 0; i <=3; i++){
		cout << "*pointer + " << i << " = " << *(pointer + i) << endl;
	}
}
void struct_pointer(){
	struct structure{
		string text;
		int numbers[100];
	} structure1;
	structure *pointer = &structure1;
	pointer -> text = "Whoah, using the arrow operator instead of (*pointer).text";
	cout << structure1.text << endl; //or pointer -> text
}
int main() {
	struct_pointer();
	return 0;
}	