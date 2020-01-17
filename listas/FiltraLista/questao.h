//
// Created by msobral on 16/08/2019.
//

#ifndef PROG_QUESTAO_H
#define PROG_QUESTAO_H

#include <string>
#include <prglib.h>

using namespace std;
using namespace prglib;

// copia para "nova" todos os valores de "lval" maiores que "limiar"
void filtra(lista<int> & nova, lista<int> & lval, int limiar);

#endif //PROG_QUESTAO_H
