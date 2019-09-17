#ifndef CONT_H
#define CONT_H

#include <iostream>
#include <prglib.h>

using namespace std;
using prglib::lista;

bool decrementa(lista<int> & lcont) {
    int ocorrencia = 0;

    lcont.inicia();


    while(!lcont.fim()) {

        int & num = lcont.proximo();

        if (num != 0) {
          num = (num - 1);
          ocorrencia++;
        }

    }

    if (ocorrencia == 0) {
        return false;
    }
    else {
        return true;
    }
}

#endif
