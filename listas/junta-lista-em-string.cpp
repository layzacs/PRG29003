// Implemente a função junta, que concatena todas as strings de uma lista, unindo-as com uma string delimitadora.
#include "junta.h"

string junta(lista<string> & l, const string & delim) {
    string final;

    l.inicia();

    while(! l.fim()) {
        if (final.empty()) {
            final = l.proximo();
        }
        else {
            final.append(delim);
            final.append(l.proximo());
        }
    }
    return final;
}
