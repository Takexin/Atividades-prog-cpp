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

  inline std::string getUsername(){return username;}
  inline void setUsername(std::string str){username = str;}

  inline std::string getPassword(){return password;}
  inline void setPassword(std::string str){password = str;}
  friend void display(client &cli);
};
void display(client &cli){
    std::cout << cli.username << '\n' << cli.password;
}


int main(){
    std::fstream stream;
    client user1(std::string("user1"), std::string("password1"));
    stream.open("data.dat", std::ios_base::binary);
    stream.write(reinterpret_cast <char *> (&user1), sizeof(client));
    
    
    std::vector <client> vect;
    stream.read(reinterpret_cast <char *> (&vect), sizeof(client));
    std::cout << sizeof(vect) << '\n' << sizeof(client);
    stream.close();
    return 0;
}