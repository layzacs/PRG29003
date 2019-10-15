/*
 * File:   fila-imp.h
 * Author: msobral
 *
 * Created on 11 de Agosto de 2016, 13:59
 */

#ifndef FILA_IMP_H
#define	FILA_IMP_H

namespace prglib {

template <typename T> fila<T>::fila(unsigned int max_itens) {
  if (max_itens == 0) throw -1;
  cap = max_itens;
  N = 0;
  inicio = 0;
  fim = 0;

  // o new cria uma área de memória para guardar valores da variável dada.
  buffer = new int[cap];
}

template <typename T> fila<T>::fila(const fila& orig) {
}

template <typename T> fila<T>::~fila() {
    // liberar a áera de memoria alocada pelo buffer.
    // Como é vetor, precisa dos colchetes.
    delete[] buffer;
}

template <typename T> fila<T>& fila<T>::operator=(const fila& outra) {
    // exemplo: N = outra.N;
}

template <typename T> void fila<T>::enfileira(const T& algo) {

    if (cheia()) throw -1;
    // guarda algo no fim da fila
    buffer[fim] = algo;
    // faz o incremento circular
    fim++;

    if (fim == cap) fim = 0;

    N++;

    //return buffer[fim];

}

template <typename T> T fila<T>::desenfileira() {

    if (vazia()) throw -1;

    int anterior = inicio;
    inicio ++;
    if (inicio == cap) inicio = 0;

    N--;

    return buffer[anterior];
}

template <typename T> T & fila<T>::frente() {
    if (vazia()) throw -1;

    return buffer[inicio];
}

template <typename T> bool fila<T>::vazia() const {
  return N == 0;
}

template <typename T> bool fila<T>::cheia() const {
    return N == cap;
}

template <typename T> unsigned int fila<T>::capacidade() const {
    return cap;
}

template <typename T> unsigned int fila<T>::comprimento() const {
    return N;
}

} // fim namespace

#endif	/* FILA_IMP_H */
