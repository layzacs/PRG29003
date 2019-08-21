#include <iostream>
#include <string>
#include <prglib.h>

using namespace std;
using namespace prglib;

int main() {
  // uma pilha com capacidade de armazenar 20 inteiros
  pilha<int> numeros(20);

  numeros.push(6); // empilha o número 6
  numeros.push(8); // empilha 8 em cima do 6
  numeros.push(10);
  numeros.push(12);

  cout << "Pilha de numeros tem comprimento=" << numeros.comprimento() << endl;

  while (! numeros.vazia()) {
    cout << "Topo da pilha: " << numeros.top() << endl;
    cout << "... desempilhou: " << numeros.pop() << endl;
  }

}
