//
// Created by msobral on 16/08/2019.
//

#ifndef PROG_QUESTAO_H
#define PROG_QUESTAO_H

#include <string>
#include <prglib.h>

using namespace prglib;
using namespace std;

template <typename T> bool testa_se_existe(arvore<T> * raiz, const T & dado) {
    lista<T> dados;
    raiz->listeInOrder(dados);

    try {
        dados.procura(dado);
    } catch (...) {
        return false;
    }
    return true;
}


#endif //PROG_QUESTAO_H
