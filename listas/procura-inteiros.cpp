#include <iostream>
#include <prglib.h>

using namespace std;
using prglib::lista;

int main() {
  lista<int> l;

  l.anexa(5);
  l.anexa(1);
  l.anexa(5);
  l.anexa(5);
  l.anexa(1);
  l.anexa(8);
  l.anexa(2);

  // "procura" dispara uma exceção se não encontrar o dado, então
  // deve-se capturar essa exceção para tratá-la.
  try {
    int res = l.procura(5);
    cout << "Encontrou o valor " << res << " na lista" << endl;
  } catch (...) {
    cout << "NÃO encontrou o valor 5 na lista" << endl;
  }

  try {
    int res = l.procura(9);
    cout << "Encontrou o valor " << res << " na lista" << endl;
  } catch (...) {
    cout << "NÃO encontrou o valor 9 na lista" << endl;
  }

  lista<int> lr;

  l.procuraMuitos(5, lr);
  cout << "Encontrou " << lr.comprimento() << " valores iguais a 5" << endl;
  lr.escrevaSe(cout, ",");
  cout << endl;
}
