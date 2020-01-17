#include "questao.h"

string expande_ipv6(const string & ip6) {
    int j=0;
    int i = 0;
    string separador = ":";
    string aux = ip6;
    lista<string> l;

    for (int k = 0; k < aux.size(); k++) {
        if (aux[k] == ':') {
            j++;
        }
    }
    while (j < 7) {

        int found = aux.find("::");
        aux.insert(found,1,':');
        j++;
    }

    //l = separa(aux, separador);
    //aux = junta(l, separador);
    for (i=0; i<aux.size(); i++) {
        if (aux[0]==':') {
            aux.insert(0,1,'0');
        }
        if (aux[i]== ':' && aux[i+1]== ':') {
            aux.insert(i + 1, 1, '0');
        }
    }
    if (aux.back() == ':') {
        aux.append(1, '0');
    }
    return aux;

}
