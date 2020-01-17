// implemente aqui sua função
#include "questao.h"

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