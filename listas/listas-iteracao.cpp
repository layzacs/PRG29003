#include <iostream>
#include <prglib.h>

using namespace std;
using prglib::lista;

int main() {
  lista<int> numeros;

  numeros.anexa(34);
  numeros.anexa(7);
  numeros.anexa(21);
  numeros.anexa(8);
  numeros.anexa(12);
  numeros.anexa(17);

  // inicia a iteração
  numeros.inicia();

  // enquanto não chegar ao fim da lista, continua a iteração
  while (! numeros.fim()) {
    // obtém o próximo dado da iteração
    int algo = numeros.proximo();

    cout << "Numero: " << algo << endl;
  }

/* Iniciando pelo fim:
#include <iostream>
#include <prglib.h>

using namespace std;
using prglib::lista;

int main() {
  lista<int> numeros;

  numeros.anexa(34);
  numeros.anexa(7);
  numeros.anexa(21);
  numeros.anexa(8);
  numeros.anexa(12);
  numeros.anexa(17);

  // inicia a iteração pelo fim da lista
  numeros.iniciaPeloFim();

  // enquanto não chegar ao início da lista, continua a iteração
  while (not numeros.inicio()) {
    // obtém o próximo dado da iteração
    int algo = numeros.anterior();

    cout << "Numero: " << algo << endl;
  }
}
*/
