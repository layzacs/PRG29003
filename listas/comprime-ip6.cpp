#include "questao.h"
#include <iostream>

string compacta_ipv6(const string & ip6) {
    string aux = ip6;

    if (aux[0] == '0' && aux[1] == ':') {
        aux.erase(0,1);
    }

    int tam = aux.size();

    if (aux[tam - 1] == '0' && aux[tam - 2] == ':') {
        aux.erase(tam - 1,1);
    }

    for (int k = 0; k < aux.size(); k++) {
        if (aux[k] == ':' && aux[k+1] == '0' && aux[k+2] == ':') {
            aux.erase(k+1, 1);
        }
    }

    for (int k = 0; k < tam; k++) {
        if (aux[k - 1] == ':' && aux[k] == ':' && aux[k+1] == ':') {
            aux.erase(k, 1);
            k=0;
        }
    }
    return aux;
}
