/* 
 * File:   lista-impl.h
 * Author: msobral
 *
 * Created on 11 de Agosto de 2016, 09:02
 */

#ifndef LISTA2_IMPL_H
#define	LISTA2_IMPL_H

namespace prglib {


template <typename T> lista<T>::lista() {
}

template <typename T> lista<T>::lista(const lista<T> & outra) {
}

template <typename T> lista<T>::lista(std::istream &inp) {

}

template <typename T> lista<T>::~lista() {
}

template <typename T> void lista<T>::insere(const T& algo) {
}

template <typename T> void lista<T>::anexa(const T& algo) {
}

template <typename T> int lista<T>::comprimento() const {
}

template <typename T> void lista<T>::esvazia() {
}

template <typename T> void lista<T>::insere(const T& algo, int posicao) {
}

template <typename T> T& lista<T>::obtem(int posicao) const {
}

template <typename T> T& lista<T>::operator[](int pos) const {
}

template <typename T> void lista<T>::escrevaSe(std::ostream& out) const {    
}

template <typename T> void lista<T>::escrevaSe(std::ostream& out, const std::string & delim) const {
}

template <typename T> T lista<T>::remove(int posicao) {
}

template <typename T> void lista<T>::retira(const T& algo) {
}

template <typename T> bool lista<T>::vazia() const {
}

template <typename T> void lista<T>::insereOrdenado(const T & algo) {
}

template <typename T> void lista<T>::ordena() {
}

template <typename T> T& lista<T>::procura(const T& algo) const {
}

template <typename T> lista<T>& lista<T>::procuraMuitos(const T& algo, lista<T>& outra) const {
}

template <typename T> std::shared_ptr<lista<T>> lista<T>::procuraMuitos(const T& algo) const {
}

template <typename T> lista<T>& lista<T>::operator=(const lista<T>& outra) {
}

template <typename T> bool lista<T>::operator==(const lista<T>& outra) const {
}

template <typename T> void lista<T>::inverte() { 
}

template <typename T> bool lista<T>::inicio() const {
}

template <typename T> bool lista<T>::fim() const {
}

template <typename T> void lista<T>::inicia() {
}

template <typename T> void lista<T>::iniciaPeloFim() {
}

template <typename T> T& lista<T>::proximo() {
}

template <typename T> T& lista<T>::anterior() {
}

template <typename T> lista<T>& lista<T>::sublista(unsigned int pos1, unsigned int pos2, lista<T> & outra) const {   
}

template <typename T> lista<T>* lista<T>::sublista(unsigned int pos1, unsigned int pos2) const {   
}

template <class T> void lista<T>::embaralha() {
}
  
} // fim namespace

#endif	/* LISTA_IMPL_H */

