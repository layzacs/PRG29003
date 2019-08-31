#include "aleatorios.h"


using namespace std;
using prglib::lista;

void adiciona_aleatorios(lista<int> & umaLista, int N) {
    int i, j;
    int num;

    srand (time(NULL));

    for (i=0; i < N; i++) {

        num = 1 + (rand() % 10);

        int tam_lista = umaLista.comprimento();

        if (i==0) {
            umaLista.anexa(num);
        }
        else {
            for (j=0; j < tam_lista; j++) {

                if (num < umaLista.obtem(j)) {
                    umaLista.insere(num, j);

                    break;
                }
            }

            if (j == tam_lista) {
                umaLista.anexa(num);
            }
        }
    }
}
