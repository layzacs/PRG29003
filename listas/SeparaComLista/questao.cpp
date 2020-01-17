#include "questao.h"

lista<string> separa(const string & texto, const string & sep) {
    int i = 0;
    int found = 0;
    string aux;
    lista<string> l;
    string inicial = texto;

    while (found != -1 && inicial.size() != 0) {
        found = inicial.find(sep);
        l.anexa(inicial.substr(0, found));
        inicial = inicial.substr (found + sep.size());
        i++;
    }
    return l;
}
