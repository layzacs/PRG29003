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
}

template <typename T> fila<T>::fila(const fila& orig) {
}

template <typename T> fila<T>::~fila() {
}

template <typename T> fila<T>& fila<T>::operator=(const fila& outra) {
}

template <typename T> void fila<T>::enfileira(const T& algo) {
}

template <typename T> T fila<T>::desenfileira() {
}

template <typename T> T & fila<T>::frente() {
}

template <typename T> bool fila<T>::vazia() const {
}

template <typename T> bool fila<T>::cheia() const {
}

template <typename T> unsigned int fila<T>::capacidade() const {
}

template <typename T> unsigned int fila<T>::comprimento() const {
}

} // fim namespace

#endif	/* FILA_IMP_H */

