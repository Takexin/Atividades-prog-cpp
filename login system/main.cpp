#include <iostream>
#include <string>
#include <fstream>
#include <vector>
std::string desiredName;
std::string desiredPassword;
class client{

private:
    std::string username;
    std::string password;
    
public:
  client(std::string us, std::string pass){username = us, password = pass;}
  client(void){};
  client(client &other_client){username = other_client.getUsername(), password = other_client.getPassword();}
  inline std::string getUsername(){return username;}
  inline void setUsername(std::string str){username = str;}

  inline std::string getPassword(){return password;}
  inline void setPassword(std::string str){password = str;}
  friend void display(client &cli);
};
void display(client &cli){
    std::cout << cli.username << '\n' << cli.password << '\n';
}

int getCharacter(std::fstream &stream, std::string filename){
    int elementsNum;
    stream.open(filename, std::ios_base::binary | std::ios_base::in);
    if (!stream.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }
    stream.read(reinterpret_cast<char * >(&elementsNum), sizeof(int));
    if(!stream.peek() == std::ifstream::traits_type::eof()){
        stream.close();
        return 0;
    }
    else{
        stream.close();
        return elementsNum;
    }
    
}
void setCharacter(std::fstream &stream, std::string filename, int num){
    stream.open(filename, std::ios_base::binary | std::ios_base::out);
    if (!stream.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }
    stream.seekp(0);
    stream.write(reinterpret_cast<char * >(&num), sizeof(int));
    stream.close();
}
void writeElement(std::fstream & stream, std::string filename, std::string numfile, client &user){
    int num = getCharacter(stream, numfile);
    num++;
    stream.open(numfile, std::ios_base::binary | std::ios_base::out);
    if (!stream.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }
    stream.write(reinterpret_cast<char * >(&num), sizeof(int));
    stream.close();
    stream.open(filename, std::ios_base::binary | std::ios_base::out | std::ios_base::app);
    if (!stream.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }
    //serialization

    //writing name
    int usernameSize = user.getUsername().length();
    stream.write(reinterpret_cast<char * >(&usernameSize), sizeof(int));

    stream.write(reinterpret_cast<char *> (&desiredName), usernameSize);

    //writing password
    int passwordSize = user.getPassword().length();
    stream.write(reinterpret_cast<char *>(&passwordSize), sizeof(int));

    stream.write(reinterpret_cast<char *> (&desiredPassword), passwordSize);
    stream.close();
}
void ReadElements(std::fstream & stream, std::fstream & numstream, std::string filename, std::string numfile){
    int num = getCharacter(numstream, numfile);
    std::cout << num << '\n';

    client userTest;
    stream.open(filename, std::ios_base::in | std::ios_base::binary);
    if (!stream.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }
    //reading name
    int nameLen;
    stream.read(reinterpret_cast<char *> (&nameLen), sizeof(int));
    std::string name;
    stream.read(reinterpret_cast<char *> (&name), nameLen);

    userTest.setUsername(name);

    //reading password
    int passLen;
    stream.read(reinterpret_cast<char *> (&passLen), sizeof(int));
    std::string pass;
    stream.read(reinterpret_cast<char *> (&pass), passLen);
    userTest.setPassword(pass);
    //display(userTest);

    // stream.read(reinterpret_cast <char *> (&userTest), num * sizeof(client));
    // std::cout << sizeof(userTest) << ' ' << sizeof(client) << '\n';
    // std::cout << "usrname" << userTest.getPassword();
    // for(int i = 0; i < num; i++){
    //     std::cout << userTest.getPassword() << '\n';
    //     std::cout << userTest.getUsername() << '\n';
    // }
}
int option;

int main(){
    //setting up filenames and file stream object
    std::fstream stream;
    std::fstream numstream;
    std::string writefile = "data.dat";
    std::string numfile = "numbers.dat";
    while(option != 4){
        std::cout << "What would you like to do?\n1:register  2:read users  3:login(pending)  4:exit\n";
        std::cin >> option;
        if(option == 1){ //register
            std::cin.ignore(1, '\n');

            //getting user input
            
            std::cout << "Username: ";
            std::cin >> desiredName;
            std::cout << "Password: ";
            std::cin >> desiredPassword;

            //creating and writing user to file
            client desiredClient(desiredName, desiredPassword);
            writeElement(stream, writefile, numfile, desiredClient);
        }
        else if(option == 2){
            ReadElements(stream, numstream, writefile, numfile);
        }
    }
    return 0;
}