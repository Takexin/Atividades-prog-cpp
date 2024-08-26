#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
    std::cout << cli.getUsername() << '\n' << cli.getPassword();
}

int getCharacter(std::fstream &stream, std::string filename){
    int elementsNum;
    stream.open(filename, std::ios_base::binary | std::ios_base::in);
    stream.read(reinterpret_cast<char * >(&elementsNum), sizeof(int));
    stream.close();
    return elementsNum;
}
void setCharacter(std::fstream &stream, std::string filename, int num){
    stream.open(filename, std::ios_base::binary | std::ios_base::out);
    stream.seekp(0);
    stream.write(reinterpret_cast<char * >(&num), sizeof(int));
    stream.close();    
}
void writeElement(std::fstream & stream, std::string filename, client &user){
    int num = getCharacter(stream, filename);
    num++;
    stream.open(filename, std::ios_base::binary | std::ios_base::out | std::ios_base::app);
    stream.seekp(0);
    stream.write(reinterpret_cast<char * >(&num), sizeof(int));
    stream.close();
    stream.open(filename, std::ios_base::binary | std::ios_base::out | std::ios_base::app);
    stream.write(reinterpret_cast<char *> (&user), sizeof(client));
    stream.close();
}
int main(){
    std::fstream stream;
    client user1(std::string("mr.president1"), std::string("obamasas last name"));
    writeElement(stream, std::string("data.dat"), user1);
    setCharacter(stream, std::string("data.dat") ,3);
    int num = getCharacter(stream, std::string("data.dat"));
    std::cout << num;//please work for gods sake
    return 0;
}