#ifndef FILA_IMP_H
#define	FILA_IMP_H

namespace prglib {

    template <typename T> fila<T>::fila(unsigned int max_itens) {
        // não permite criar uma lista com capacidade de 0 dados
        if (max_itens == 0) throw -1;

        // todos os valores relacionados a fila são inicializados
        cap = max_itens;
        N = 0;
        inicio = 0;
        fim = 0;
        // o new cria uma área de memória para guardar valores da variável passada. O vetor de tamanho especificado é criado abaixo.
        buffer = new T[cap];
    }

    template <typename T> fila<T>::fila(const fila& orig) {

        //copiamos os atributos da fila original para a nova fila
        N = orig.N;
        cap = orig.cap;
        inicio = orig.inicio;
        fim = orig.fim;
        // o buffer não pode ser copiado como os outros parâmetros. Ele é deletado e criamos um novo, copiando da lista anterior seus valores.
        buffer = new T[cap];


        for (int i = 0; i < cap; i++) {
            buffer[i] = orig.buffer[i];
        }

    }

    template <typename T> fila<T>::~fila() {
        // liberar a áera de memoria alocada pelo buffer.
        // Como é vetor, precisa dos colchetes.
        delete[] buffer;
    }

    template <typename T> fila<T>& fila<T>::operator=(const fila& outra) {

        // copiamos os atributos da outra fila.
        inicio = outra.inicio;
        fim = outra.fim;
        N = outra.N;
        cap = outra.cap;

        // o buffer anterior é deletado e um novo é criado, com os dados do buffer da outa fila copiados.
        delete[] buffer;
        buffer = new T[cap];

        for (int i = 0; i < N; i++) {
            buffer[i] = outra.buffer[i];
        }
    }

    template <typename T> void fila<T>::enfileira(const T& algo) {
        // se fila cheia, dispara exceção.
        if (cheia()) throw -1;
        // adicionamos o novo dado na primeira posição livre, apontada pela variavel fim.
        buffer[fim] = algo;

        // se ao somar um a variavel fim chegarmos no valor máximo da fila, fim se torna igual a 0.
        if (fim+1 == cap) {
            fim = 0;
        } else {
            fim++;
        }
        N++;

    }

    template <typename T> T fila<T>::desenfileira() {
        // se fila vazia ger exceção.
        if (vazia()) throw -1;

        // o valor a ser desenfileirado é o que se encontra no inicio da fila (first in first out)
        int desenfileirado = inicio;
        // o inicio da fila passa a ser o valor seguinte.
        inicio++;
        // se o inicio estiver na ultima posição do vetor, ele passar a apontar para a posição 0 (fila circular).
        if (inicio == cap) inicio = 0;
        // dado desenfileirado diminui a quantidade de dados da fila em 1.
        N--;
        // retornamos valor desenfileirado
        return buffer[desenfileirado];
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

    template <typename T> void fila<T>::esvazia() {
        if (vazia()) return;
        delete[] buffer;
        buffer = new T[cap];
        N = 0;

    }



} // fim namespace

#endif	/* FILA_IMP_H */
