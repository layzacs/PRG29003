#include <iostream>
#include <string>
#include "prglib.h"

using namespace std;

int main() {
  // criando a variável numeros do tipo fila. Ela guarda inteiros
  prglib::fila<int> numeros(20);

  // uma fila com capacidade de armazenar 20 string
  prglib::fila<string> coisas(20);

  // começa a enfileirar números dentro da fila numeros
  numeros.enfileira(6);
  numeros.enfileira(8);
  numeros.enfileira(10);
  numeros.enfileira(12);

  // começa a enfileirar strings dentro da fila coisas
  coisas.enfileira("banana");
  coisas.enfileira("graviola");
  coisas.enfileira("sapoti");
  coisas.enfileira("siriguela");
  coisas.enfileira("caju");

  cout << "Fila de numeros tem comprimento=" << numeros.comprimento() << endl;
  cout << "Fila de string tem comprimento=" << coisas.comprimento() << endl;

  // enquanto a fila não estiver vazia, os valores são desenfileirados
  while (! numeros.vazia()) {
    cout << "Numero: " << numeros.desenfileira() << endl;
  }

  while (! coisas.vazia()) {
    cout << "String: " << coisas.desenfileira() << endl;
  }
}
