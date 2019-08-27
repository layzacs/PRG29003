#include <cstdlib>
#include <prglib.h>
#include <iostream>
#include <string>

using namespace std;
using prglib::lista;

int main(int argc, char** argv) {
  int pos=0;
  string palavra;
  lista<string> lista;


// A lista naturalmente já insere novos valores na primeira posição, de forma que o primeiro valor inserido vai se distanciando do início da lista a medida que os dados são inseridos.
  while (pos < 10 ) {
      cin >> palavra;
      lista.insere(palavra);
      pos++;
  }
  lista.escrevaSe(cout, " ");

}
