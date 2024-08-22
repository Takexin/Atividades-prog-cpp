#include <iostream>
#include <fstream>
#include <string>
#include <vector>

static int item_num = 0;
class item{
public:
    std::string name;
    item(std::string s){
        name = s;
        item_num++;
        self_number=item_num;
    }
    item(item &other_item){
        name = other_item.name;
        self_number = other_item.self_number;
    }
    item(){
}

    int get_num(){return self_number;}
    void set_num(int num){self_number = num;}
    friend void display(item &item){
        std::cout << "Item name: " << item.name << '\n';
        std::cout << "Item number: " << item.get_num() << '\n';
    }
    void operator=(item & other_item){
        name = other_item.name;
        set_num(other_item.get_num());
    }
    friend std::ostream &operator<<(std::ostream &stream, item &selected_item){
        std::cout << "Item name: " << selected_item.name << "\nItem number: " << selected_item.self_number << '\n';
        return stream;
    }
    friend void append_to_file(item &item, std::ofstream &file){
        file << "Item name: " << item.name << "\nItem number: " << item.get_num() << '\n';
    }
private:
    int self_number;
};

std::string file_name;
std::vector<item> item_vector;
void main_loop(std::ofstream &file, std::ifstream &file_read){
    int option = 0;
    while (option != 4)
    {
        std::cout << "What would you like to do?\nAdd item: 1\nRead Items: 2\nClear items: 3 \nExit: 4" << std::endl;
        std::cin>> option;
        std::cout << "\n\n\n\n\n\n\n\n\n\n";
        if(option==1){
            if(!file.is_open()){
                file.open(file_name, std::ios_base::out | std::ios_base::binary);
            }
            std::cin.ignore(1, '\n');
            std::string desired_item;
            std::cout << "Write the name of the desired item: ";
            std::getline(std::cin, desired_item); 
            item desired_object(desired_item);
            
            file.write(reinterpret_cast< char *>(&desired_object), sizeof(item));
            std::cout << "Item created with the name: " << desired_item << '\n';
            file.close();
        }
        else if(option == 2){
            std::cin.ignore(1, '\n');

	    item b;
            file_read.open(file_name, std::ios_base::in | std::ios_base::binary);
            file_read.read(reinterpret_cast<char *> (&b), sizeof(item));
	    display(b);           
        }
        else if(option == 3){
            file.close();
            file.open(file_name);
            file << " ";
            std::cout << "File cleared \n";
        }
    }
    file.close();
    file_read.close();
    
}
int main(){   
    std::cout << "Name of the file: ";
    std::getline(std::cin, file_name);
    if (file_name == ""){
        file_name = "data.dat";
    }
    std::cout << "You typed: " << file_name << '\n';


    std::ofstream fout;
    fout.open(file_name, std::ios_base::app);


    std::ifstream fin(file_name);
    if (!fout.is_open() || fin.fail()){
        std::cout << "Error: couldn't open file...\n";
        return 1;
    }

    
    main_loop(fout, fin);
    return 0;
}
