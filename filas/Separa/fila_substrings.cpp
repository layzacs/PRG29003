#ifndef SEPARADOR_H
#define SEPARADOR_H
#include "fila_substrings.h"
#include <prglib.h>
#include <string>

using std::string;
using prglib::fila;

void separa(string algo, char sep, fila<string> & q) {
    string substr;
    int pos_inicial, pos_final, tam;

    while (algo.find(sep) > 0) {
        pos_inicial = algo.find(sep);

        if (algo.find(sep, pos_inicial) < 0) {
            substr = algo.substr(pos_inicial);
            q.enfileira(substr);
            break;
        }
        if (algo.find(sep, pos_inicial) > 0) {
            pos_final = algo.find(sep, pos_inicial);
            tam = pos_final - pos_inicial;
            substr = algo.substr(pos_inicial, tam);
            q.enfileira(substr);
            algo.erase(0, tam);
        }

    }
}

#endif
