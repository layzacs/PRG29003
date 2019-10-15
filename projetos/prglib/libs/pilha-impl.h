/* 
 * File:   pilha-impl.h
 * Author: msobral
 *
 * Created on 11 de Agosto de 2016, 13:59
 */

#ifndef PILHA_IMPL_H
#define	PILHA_IMPL_H

#include "pilha.h"


namespace prglib {
    
template <typename T> pilha<T>::pilha(unsigned int umaCapacidade) {
}
 
template <typename T> pilha<T>::pilha(const pilha& outra) {
}
 
template <typename T> pilha<T>::~pilha() {
}

template <typename T> pilha<T> & pilha<T>::operator=(const pilha<T> & outra) {
}
 
template <typename T> void pilha<T>::esvazia() {
}
 
template <typename T> void pilha<T>::push(const T & dado) {
}
 
template <typename T> T pilha<T>::pop() {
}
 
template <typename T> const T& pilha<T>::top() const{
}

template <typename T> unsigned int pilha<T>::capacidade() const {
}

template <typename T> bool pilha<T>::cheia() const {
}

template <typename T> bool pilha<T>::vazia() const {
}

template <typename T> unsigned int pilha<T>::comprimento() const {
}

}

#endif	/* PILHA_IMPL_H */

