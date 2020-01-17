#include "questao.h"

arvore<int> * balanceia_condicional(arvore<int> * raiz) {

    int altura = raiz->altura();
    int dados = raiz->tamanho();


    // A menor altura possivel para uma arvore com x dados é dada pela formula abaixo:
    int menor_altura = (1 + log2(1+dados));
    // pela altura da árvore podemos saber quantos dados ela comportaria se estivesse perfeitamente balanceada.
    //

    // enquanto a altura atual não for menor ou igual ao dobro da menor altura possivel, a arvore é balanceada de novo.
    while (altura >= 2*menor_altura) {
        raiz->balanceia();

        altura = raiz->altura();
    }
    return raiz;

}
