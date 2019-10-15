#ifndef QUESTAO3_H
#define QUESTAO3_H

#include <prglib.h>

using prglib::arvore;
using prglib::lista;

template <typename T> int compara_arvores(arvore<T> * a1, arvore<T> * a2) {

    lista<T> arv1, arv2;

    if (a1 == nullptr) {
        if (a2 == nullptr) return 2;
        return 0;
    }
    if (a2 == nullptr) return 0;


    a1->listePreOrder(arv1);
    a2->listePreOrder(arv2);

    if (arv1 == arv2) {
        return 2;
    } else {
        arv1.ordena();
        arv2.ordena();
        if (arv1 == arv2) {
            return 1;
        } else {
            return 0;
        }
    }
}

#endif
