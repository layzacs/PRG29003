/* 
 * File:   arvore-impl.h
 * Author: sobral
 *
 * Created on 8 de Outubro de 2016, 19:37
 */

#ifndef ARVORE_IMPL_H
#define	ARVORE_IMPL_H

namespace prglib {

template <typename T> arvore<T>::~arvore() {    
}
    
template <typename T> arvore<T>::arvore() {    
}

template <typename T> arvore<T>::arvore(const T & dado) {
    data = dado;
    pai = this; // pai aponta para ele mesmo
    esq = nullptr;
    dir = nullptr;
}

// cria arvore a partir de um arquivo
template <typename T> arvore<T>::arvore(istream &inp) {

}

template <typename T> arvore<T>::arvore(prglib::lista<T> &dados) {

}

template <typename T> void arvore<T>::adiciona(const T & algo) {
    arvore<T> * atual = this; // define um nodo apontando para a raiz da arvore

    while (true) {
        if (algo == atual->data) {
             atual->data = algo;
             return;
        }
        if (algo < atual->data) {
            if (atual->esq != nullptr) {
                atual = atual->esq;
            } else {
                auto novo = new arvore<T>(algo);
               atual->esq = novo;
               novo->pai = atual;
                return;
            }
        } else {
            if (atual->dir != nullptr) {
                atual = atual->dir;
            } else {
                auto novo = new arvore<T>(algo);
                atual->dir = novo;
                novo->pai = atual;
                return;
            }

        }
    }
}

// obtem retorna o dado
template <typename T> const T& arvore<T>::obtem(const T & algo) const {
    const arvore<T> * atual = this;   // aqui temos q chamar como const pq a função é const, significando que ela não modifica em momento nenhum a árvore.

    while (atual != nullptr) {
        if (atual->data == algo) {
            return atual->data;
        }

        if (algo > atual->data) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }
    throw -1; // dado n encontrado
}

template <typename T> const T& arvore<T>::obtem() const {
    return data;
}

template <typename T> void arvore<T>::listeEmLargura(lista<T> & result) {
}

template <typename T> void arvore<T>::listeInOrder(lista<T> & result) {
}

template <typename T> void arvore<T>::listePreOrder(lista<T> & result) {
}

template <typename T> void arvore<T>::listePostOrder(lista<T> & result) {
}

template <typename T> unsigned int arvore<T>::tamanho() const {
}

template <typename T> int arvore<T>::fatorB()  {
}

template <typename T> unsigned int arvore<T>::altura()  {
}

template <typename T> arvore<T>* arvore<T>::balanceia() {
}

template <typename T> arvore<T>* arvore<T>::balanceia(bool otimo) {
}

template <typename T> void arvore<T>::inicia() {
}

template <typename T> T& arvore<T>::proximo() {
}

template <typename T> bool arvore<T>::fim() {
}

template <typename T> T& arvore<T>::obtemMenor() const{
}

template <typename T> T& arvore<T>::obtemMaior() const{
}

template <typename T> void arvore<T>::obtemMenoresQue(lista<T> & result, const T & algo) {
}

template <typename T> void arvore<T>::obtemMaioresQue(lista<T> & result, const T & algo) {
}

template <typename T> void arvore<T>::obtemIntervalo(lista<T>& result, const T& start, const T& end) {
}

};

#endif	/* ARVORE_IMPL_H */

