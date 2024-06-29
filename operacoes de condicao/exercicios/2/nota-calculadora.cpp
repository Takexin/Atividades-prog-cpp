#include <iostream>
using namespace std;


/*2 - Elabore um programa que leia 3 notas escolares de um aluno, calcule a média e exiba a mensagem
APROVADO para médias maiores ou iguais a 6 e a mensagem EXAME para médias inferiores a 6. Exiba
também a media.
*/
void calcular(){
    float nota1, nota2, nota3, media;
    cout << "Digite as 3 notas: ";
    cin >> nota1 >> nota2 >> nota3;
    media = (nota1 + nota2 + nota3) / 3;
    if(media >= 6){
        cout << "APROVADO" << "\n";
        cout << "Media: " << media << "\n\n" << "" << endl;
    }
    else{
        cout << "REPROVADO" << "\n";
        cout << "Media: " << media << "\n\n" << "" << endl;
    }
}
int main(){
    while(true){
        calcular();
    }
    return 0;
}