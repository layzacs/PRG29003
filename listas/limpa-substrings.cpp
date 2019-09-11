#include "bordas.h"

void limpa_bordas(lista<string> & l) {
    //int &x = l.obtem(1) - para modificar a string na posição 1 sem precisar tirar e inserir o dado. O jeito certo de fazer isso é usando iteração.
    int tam = l.comprimento();
    // Isso NAÕ DEVE SER FEITO, é preciso usar iteração
    for (int i = 0; i<tam; i++) {
        string &x = l.obtem(i);

        int inicio = x.find_first_not_of(" ");
        x.erase(0, inicio);

        int final = x.find_last_not_of(" ");
        x.erase((final+1), string::npos);

        }

    }
