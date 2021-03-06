#ifndef PILHA_IMPL_H
#define	PILHA_IMPL_H

namespace prglib {

    template <typename T> pilha<T>::pilha(unsigned int umaCapacidade) {
        // Impossibilita criar pilha com capacidade 0
        if (umaCapacidade == 0) throw -1;
        // Inicializamos as variáveis da nova pilha
        cap = umaCapacidade;
        topo = 0;
        buffer = new T[cap];
    }

    template <typename T> pilha<T>::pilha(const pilha& outra) {
        // copiamos os atributos da pilha outra
        cap = outra.cap;
        topo = outra.topo;

        // é criado um buffer para a nova pilha. Os dados do buffer da outra pilha são copiados para ela.
        buffer = new T[cap];

        for (int i = 0; i < topo; i++) {
            buffer[i] = outra.buffer[i];
        }
    }

    template <typename T> pilha<T>::~pilha() {
        delete[] buffer;
    }

    template <typename T> pilha<T> & pilha<T>::operator=(const pilha<T> & outra) {
        // copiamos os atributos da pilha outra
        cap = outra.cap;
        topo = outra.topo;
        // excluimos o buffer anterior da pilha.
        delete[] buffer;
        // é criado um buffer para a nova pilha. Os dados do buffer da outra pilha são copiados para ela.
        buffer = new T[cap];

        for (int i = 0; i < topo; i++) {
            buffer[i] = outra.buffer[i];
        }
    }

    template <typename T> void pilha<T>::esvazia() {
        // deletamos o buffer e criamos um novo (para limpar os dados)
        delete[] buffer;
        buffer = new T[cap];
        // o topo agora retorna a 0.
        topo = 0;

    }

    template <typename T> void pilha<T>::push(const T & dado) {
        if (cheia()) throw -1;
        // subimos uma posição do vetor e adicionamos o dado a ele.
        topo++;
        buffer[topo] = dado;

    }

    template <typename T> T pilha<T>::pop() {
        if (vazia()) throw -1;

        // o dado a ser desempilhado se encontra no topo (first in last out)
        int desempilhado = topo;
        // topo passa a ser o dado anterior
        topo--;

        // retornamos o dado a ser desempilhado (nota-se que ele não foi excluido. Ele será sobrescrito quando um novo dado for inserido na pilha).
        return buffer[desempilhado];
    }

    template <typename T> const T& pilha<T>::top() const{
        return buffer[topo];
    }

    template <typename T> unsigned int pilha<T>::capacidade() const {
        return cap;
    }

    template <typename T> bool pilha<T>::cheia() const {
        return topo == cap;
    }

    template <typename T> bool pilha<T>::vazia() const {
        return topo == 0;
    }

    template <typename T> unsigned int pilha<T>::comprimento() const {
        return topo;
    }

}

#endif	/* PILHA_IMPL_H */
