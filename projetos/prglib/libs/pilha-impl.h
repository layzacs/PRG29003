#ifndef PILHA_IMPL_H
#define	PILHA_IMPL_H

#include "pilha.h"

namespace prglib {
    
template <typename T> pilha<T>::pilha(unsigned int umaCapacidade) {
    topo = 0;
    N = umaCapacidade;
    buffer = new T [N];
}
 
template <typename T> pilha<T>::pilha(const pilha& outra) {
}
 
template <typename T> pilha<T>::~pilha() {
    delete [] buffer;
}

template <typename T> pilha<T> & pilha<T>::operator=(const pilha<T> & outra) {
    N = outra.N;
    topo = outra.topo;
    delete[] buffer;
    buffer = new T [N];
    
    for (int i = 0; i < topo; i++) {
        buffer[i] = outra.buffer[i];
    }
}
 
template <typename T> void pilha<T>::esvazia() {
    buffer == 0;
}
 
template <typename T> void pilha<T>::push(const T & dado) {
    if (cheia()) {
        throw -1;
    }
    buffer[topo] = dado;
        topo++;
}
 
template <typename T> T pilha<T>::pop() {
    if (vazia()) {
        throw -1;
    }
    topo--;
    T dado = buffer[topo];
    return dado;
}
 
template <typename T> const T& pilha<T>::top() const{
    return buffer[topo - 1];
}

template <typename T> unsigned int pilha<T>::capacidade() const {
    return N;
}

template <typename T> bool pilha<T>::cheia() const {
    return N == topo;
}

template <typename T> bool pilha<T>::vazia() const {
    return topo == 0;
}

template <typename T> unsigned int pilha<T>::comprimento() const {
    return topo;
}

}

#endif	/* PILHA_IMPL_H */

