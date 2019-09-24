/*
//questao.h

#include <string>
#include <prglib.h>

using namespace std;
using namespace prglib;

double reduz(lista<double> & l, int operacao);
*/

// main.cpp
#include "questao.h"

double reduz(lista<double> & l, int operacao){

    l.inicia();

    if (operacao == 1) {
        double somatorio = 0;

        while (!l.fim()) {

            somatorio = somatorio + l.proximo();
        }
        return somatorio;

    }
    if (operacao == 2) {
        double produto = 0;
        while (!l.fim()) {
            if (produto == 0) {
                produto = l.proximo();
            }
            else {
                produto = produto*l.proximo();
            }
        }
    return produto;

    }
}
