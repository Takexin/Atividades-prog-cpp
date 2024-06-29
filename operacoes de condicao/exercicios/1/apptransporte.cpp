#include <iostream>
using namespace std;

/*1 - Elabore um script para um app de transporte com as seguintes regras:
- Cada KM rodado custa R$3,50
- O App deve calcular 75% do total para o motorista e 25% para o APP.
- Observação: Caso o valor da viagem ultrapasse R$100,00, o motorista fica com 80% e o APP com 20%.
Exiba o total, o valor do Motorista e o valor do APP
*/
int main(){
    float km = 3.50;
    int kilometragem;
    float res;
    cout << "Digite o numero de kilometros: ";
    cin >> kilometragem;
    res = kilometragem * km;
    if(res > 100){
        cout << "Valor total: " << res << "\n";
        cout << "Valor motorista(80%): " << res * 0.8 << "\n";
        cout << "Valor APP(20%): " << res * 0.2 << endl;
    }
    else{
        cout << "Valor total: " << res << "\n";
        cout << "Valor motorista(75%): " << res * 0.75 << "\n";
        cout << "Valor APP(25%): " << res * 0.25 << endl;
    }
    return 0;

}