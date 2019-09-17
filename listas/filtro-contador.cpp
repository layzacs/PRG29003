#include "questao.h"

void filtra(lista<int> & nova, lista<int> & lval, int limiar) {


    lval.inicia();

    while (!lval.fim()) {
        int i = 0, aux = lval.proximo();
        if ( aux > limiar) {
            nova.anexa(aux);
        }
    }
}
