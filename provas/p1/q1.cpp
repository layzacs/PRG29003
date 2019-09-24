//Escreva um programa que ordena números usando pilha.
//Os números estão armazenados em um arquivo, cujo nome é informado no primeiro argumento de linha de comando.
#include <iostream>
#include <string>
#include <prglib.h>
#include <fstream>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {

    ifstream arq(argv[1]);

    pilha<int> numeros(1000);

    int num=0;

    if (! arq.is_open()) {
        cout << "arquivo invalido" << endl;
    }

    while (arq >> num) {
        pilha<int> aux(1000);

        if (numeros.vazia()) {
            numeros.push(num);
        } else {
            while (num > numeros.top()) {
                int a = numeros.pop();
                aux.push(a);
                if (numeros.vazia()) {
                    break;
                }
            }
            numeros.push(num);
            while (! aux.vazia()) {
                int b = aux.pop();
                numeros.push(b);
            }
        }
    }
    while (!numeros.vazia()) {
        int x = numeros.pop();
        cout << x << endl;
    }
}
