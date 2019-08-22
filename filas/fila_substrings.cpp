#ifndef SEPARADOR_H
#define SEPARADOR_H
#include <prglib.h>
#include <string>

using std::string;
using prglib::fila;

void main() {
  string algo;
  char sep;

  fila<string> & q) {
    string substr;
    int pos_inicial, pos_final, tam;

    for (; algo.find(sep, 0) < 0;) {
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
            algo.erase(pos_inicial, tam);
        }

    }
}
