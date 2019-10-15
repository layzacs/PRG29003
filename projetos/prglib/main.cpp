/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
 
  // desenfileira um por um dos dados da fila, mostrando-os na tela, até
  // que a fila fique vazia
  while (! f1.vazia()) cout << "Dado: " << f1.desenfileira() << endl;
 
  return 0;
}