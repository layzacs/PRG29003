#include "questao.h"


void capIniciais(lista<string> & palavras) {
    palavras.inicia();

    while (!palavras.fim()) {
        string & x = palavras.proximo();

        x[0] = toupper(x[0]);
    }
}
