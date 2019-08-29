#ifndef ORD_H
#define ORD_H

#include <prglib.h>

using prglib::lista;

bool ordenada(lista<int> & l) {
    // implemente aqui sua função
    int i, j=0;

    for (i=0; i < l.comprimento(); i++) {

        if (j > l.obtem(i)) {
            return false;
        }

        j = l.obtem(i);
    }
    return true;
}


#endif
