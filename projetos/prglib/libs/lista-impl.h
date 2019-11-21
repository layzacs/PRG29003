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
    len = 0;
    atual = &guarda;
}

//todo testar copia de listas
template <typename T> lista<T>::lista(const lista<T> & outra) {
    atual = outra.guarda;

    while (len < outra.len) {
        auto Nodo = outra.guarda.proximo;
        Nodo.conecta(guarda->proximo);
        len++;
    }

}

template <typename T> lista<T>::lista(std::istream &inp) {
}

template <typename T> lista<T>::~lista() {
}

template <typename T> typename lista<T>:: Nodo * lista<T>::obtem_nodo(int posicao) {
    Nodo * ptr = guarda.proximo;

    while (posicao-- > 0) ptr = ptr->proximo;

    return ptr;
}

template <typename T> void lista<T>::insere(const T& algo) {
    auto nodo = new Nodo(algo);

    nodo->conecta(guarda.proximo);

    len++;
}

template <typename T> void lista<T>::anexa(const T& algo) {
    auto nodo = new Nodo(algo);

    nodo->conecta(&guarda);

    len++;
}

template <typename T> void lista<T>::anexatodos(const lista<T> & dados) {

    if (dados.len < 1) return;

    // cria nodo ptr que aponta para o primeiro nodo da lista dados
    Nodo * ptr = dados.guarda.proximo;

    // enquanto o ptr for diferente do ultimo nodo da lista dados
    do {
        // criamos um nodo que contem os dados do nodo ptr
        auto nodo = new Nodo(ptr->dado);
        // conectamos o nodo criado na lista
        nodo->conecta(&guarda);
        // aumentamos o tamanho da lista em 1
        len++;
        // ptr agora é igual ao próximo nodo da lista dados
        ptr = ptr->proximo;
        } while (ptr->anterior != dados.guarda.anterior);

}


template <typename T> int lista<T>::comprimento() const {
    return len;
}

template <typename T> void lista<T>::esvazia() {

    // caso a lista esteja vazia, nada é feito.
    // enquanto a lista não estiver vazia, removemos o ultimo dado da lista.
    while (!vazia()) {
        remove(len - 1);
    }
}

template <typename T> void lista<T>::insere(const T& algo, int posicao) {
    // Se a posição for maior que o tamanho da lista, o dado apenas é anexado a lista.
    // Usamos a função pronta anexa.
    if (posicao >= len) anexa(algo);
    else {
        // cria um novo nodo
        auto nodo = new Nodo(algo);
        // obtemos o nodo da posição em que desejamos inserir o novo nodo
        Nodo * ptr = obtem_nodo(posicao);
        // o novo nodo é conectado ao nodo que anteriormente se encontrava na posição.
        nodo->conecta(ptr);
        // aumenta o comprimento da lista em 1.
        len++;

    }
}

template <typename T> T& lista<T>::obtem(int posicao) const {
    if (posicao >= len) throw -1;

    Nodo * ptr = obtem_nodo(posicao);

    return ptr->dado;
}

template <typename T> T& lista<T>::operator[](int pos) const {
    return obtem(pos);
}

template <typename T> void lista<T>::escrevaSe(std::ostream& out) const {    
// usa como base a função escrevaSe completa
escrevaSe(out, "\n");
}

template <typename T> void lista<T>::escrevaSe(std::ostream& out, const std::string & delim) const {

    if (!vazia()) {
        Nodo *ptr = guarda.proximo;

        // guarda.anterior é o último nodo da lista.
        while (ptr != guarda.anterior) {
            out << ptr->dado << delim;
            ptr = ptr->proximo;
        }

        // retorna o último dado da lista.
        out << guarda.anterior->dado;
    }
}

template <typename T> T lista<T>::remove(int posicao) {
    // se a posição dada não é uma posição valida na lista (maior que o tamanho dela)
    if (posicao >= len) throw -1;
    else {
        // obtem o valor do nodo na posicao x
        Nodo * ptr = obtem_nodo(posicao);
        // desconecta o nodo que é pra ser removido
        ptr->desconecta();
        // acessa o dado do ptr
        T dado = ptr->dado;

        // destroi o nodo
        delete ptr;

        len--;

        //retorna o dado do nodo excluido.
        return dado;

    }
}

template <typename T> void lista<T>::retira(const T& algo) {
}

template <typename T> bool lista<T>::vazia() const {

    return len == 0;
}

template <typename T> void lista<T>::insereOrdenado(const T & algo) {
}

template <typename T> void lista<T>::ordena() {
    // algoritmo de ordenamento bolha!
    // inicialmente já excluimos listas que não possuem mais de 2 nodos.
    if (len < 2) return;

    auto nodo = &guarda;

    for (Nodo *j = guarda.anterior; j!= guarda.proximo; j = j->anterior) {
        for (Nodo *k = guarda.proximo; k != j; k = k->proximo) {
            // se o dado do nodo k for maior que o dado do nodo antecessor do k eles estão na ordem errada.
            if (k->dado > k->proximo->dado) {
                T aux = k->dado;
                k->dado = k->proximo->dado;
                k->proximo->dado = aux;
            }
        }
    }

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


    if (len >= 2) return;
    // pegamos endereço do guarda
    Nodo *ptr = &guarda;

    // invertemos os ponteiros de um nodo e depois copiamos ele para a variavel ptr
    // repete até voltar ao primeiro dado da lista (guarda)
    do {
        Nodo *aux = ptr->proximo;
        ptr->proximo = ptr->anterior;
        ptr->anterior = aux;
        ptr = aux;

    } while (ptr != &guarda);
}

template <typename T> bool lista<T>::inicio() const {
}

template <typename T> bool lista<T>::fim() const {
    // se o nodo atual na iteração for igual ao guarda (primeiro nodo) a iteração chegou ao final.
    return atual == &guarda;
}

template <typename T> void lista<T>::inicia() {
    // nesse caso, guarda.proximo é o primeiro nodo da lista.
    atual = guarda.proximo;
}

template <typename T> void lista<T>::iniciaPeloFim() {
    atual = guarda.anterior;

}

template <typename T> T& lista<T>::proximo() {

    if (fim()) throw -1;

    // atual foi setado na função inicia().
    // Aqui damos o valor do atual para o dado a ser retornado e mudamos o valor de atual para o próximo dado.
    T& dado = atual->dado;
    atual = atual->proximo;

    return dado;
}

template <typename T> T& lista<T>::anterior() {

    if (fim()) throw -1;

    // basicamente o mesmo que o proximo, mas em vez de mudar o valor do nodo atual para o proximo nodo, mudaremos para o nodo anterior.
    T& dado = atual->dado;
    atual = atual->anterior;

    return dado;
}

template <typename T> lista<T>& lista<T>::sublista(unsigned int pos1, unsigned int pos2, lista<T> & outra) const {   
}

template <typename T> lista<T>* lista<T>::sublista(unsigned int pos1, unsigned int pos2) const {   
}

template <class T> void lista<T>::embaralha() {

    if (len < 2) return;

    int i = len - 1;
    while (i>0) {
        int j = rand() % (i+1);
        if (i != j) {
            T &dado1 = obtem(j);
            T &dado2 = obtem(j);
            T aux = dado1;
            dado1 = dado2;
            dado2 = aux;
        }


        i--;
    }

}
  
} // fim namespace

#endif	/* LISTA_IMPL_H */

