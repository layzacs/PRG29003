#ifndef COPIAR_H
#define COPIAR_H

#include <string>
#include <prglib.h>

using prglib::lista;
using std::string;

void copia_lista(lista<string> & original, lista<string> & nova) {
    string palavra;

    for (int i=0; i < original.comprimento(); i++) {
        palavra = original.obtem(i);
        nova.anexa(palavra);
    }
}

#endif
