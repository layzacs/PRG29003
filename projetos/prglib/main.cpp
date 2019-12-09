#include<iostream>
#include <prglib.h>

using namespace std;
using prglib::fila;

int main() {
    fila<int> f1(10); // cria uma fila chamada "f1", com capacidade 10


    // enfileira os números 5, 8, 2 e 4 na fila "f1"
    f1.enfileira(5);
    f1.enfileira(8);
    f1.enfileira(2);
    f1.enfileira(4);

    fila<int> f2(f1);

    while (!f1.vazia()) {
        cout << f1.desenfileira() << endl;
    }

    while (!f2.vazia()) {
        cout << f2.desenfileira() << endl;
    }

    // desenfileira um por um dos dados da fila, mostrando-os na tela, até
    // que a fila fique vazia
    return 0;
}