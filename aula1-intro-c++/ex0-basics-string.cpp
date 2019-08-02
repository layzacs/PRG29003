// Compilando este código: g++ -std=c++11 -o ex0 ex0.cpp

#include <iostream>
#include <string>

using namespace std;

int main() {
  string nome, sobrenome, nomeCompleto;

  cout << "Nome: ";
  cin >> nome;
  cout << "Sobrenome: ";
  cin >> sobrenome;

  nomeCompleto = nome + " " + sobrenome;

  cout << "Nome completo: " << nomeCompleto << endl;
}

//Como ficaria o código em C:
//#include <stdio.h>
//#include <string.h>

//int main() {
//  char nome[32], sobrenome[32];
//  char nomeCompleto[64];

//  printf("Nome: ");
//  scanf("%32s", nome);
//  printf("Sobrenome: ");
//  scanf("%32s", sobrenome);

//  strcpy(nomeCompleto, nome);
//  strcat(nomeCompleto, " ");
//  strcat(nomeCompleto, sobrenome);

//  printf("Nome completo: %s\n", nomeCompleto);

//  return 0;
//}
