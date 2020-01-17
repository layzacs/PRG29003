#ifndef PRGLIB_LISTA_IMPL_H
#define	PRGLIB_LISTA_IMPL_H

#include "lista.h"

using std::string;

namespace prglib {

    // DONE
    template<typename T> lista<T>::lista() {
        // iniciamos uma lista vazia
        len = 0;
        atual = &guarda;
    }

    // DONE
    template<typename T> lista<T>::lista(const lista <T> &outra) {
        len = 0;
        atual = &guarda;
        Nodo *ptr = outra.guarda.proximo;

        // enquanto a lista nova for menor que a outra lista, criamos um nodo, copiamos o próximo nodo da lista e conectamos este novo nodo ao anterior.
        while (len < outra.len) {
            // criamos um nodo com o conteudo do proximo nodo da lista de origem
            auto nodo = new Nodo(ptr->dado);
            // conectamos o nodo criado ao ultimo nodo da lista nova
            nodo->conecta(&guarda);
            // tamanho da lista aumenta
            ptr = ptr->proximo;
            len++;
        }

    }

    // DONE
    template<typename T> lista<T>::lista(std::istream &inp) {
        len = 0;
        atual = &guarda;
        string dado;
        while (inp >> dado) {
            auto nodo = new Nodo(dado);
            nodo->conecta(atual);
            len++;
        }

    }

    template<typename T> lista<T>::~lista() {

        while (!vazia()) {
            remove(len-1);
        }
    }

    // DONE
    template<typename T> typename lista<T>::Nodo *lista<T>::obtemNodo(int posicao) const {
        Nodo *ptr = guarda.proximo;

        while (posicao-- > 0) ptr = ptr->proximo;

        return ptr;
    }

    // DONE
    template<typename T> void lista<T>::insere(const T &algo) {
        // criamos um novo nodo com o dado passado
        auto nodo = new Nodo(algo);

        // o nodo é conectado ao ultimo nodo da lista, sendo assim inserido no inicio da lista.
        nodo->conecta(guarda.proximo);
        // comprimento da lista aumenta em 1
        len++;
    }

    // DONE
    template<typename T> void lista<T>::insere(const T &algo, int posicao) {
        // Se a posição for maior que o tamanho da lista, o dado apenas é anexado a lista.
        // Usamos a função pronta anexa.
        if (posicao >= len) anexa(algo);
        else {
            // cria um novo nodo com o dado passado
            auto nodo = new Nodo(algo);
            // obtemos o nodo da posição em que desejamos inserir o novo nodo
            Nodo *ptr = obtemNodo(posicao);
            // o novo nodo é conectado ao nodo que anteriormente se encontrava na posição.
            nodo->conecta(ptr);
            // aumenta o comprimento da lista em 1.
            len++;
        }
    }

    // DONE
    template<typename T> void lista<T>::anexa(const T &algo) {
        // criamos um novo nodo com o dado passado
        auto nodo = new Nodo(algo);

        // conectamos o nodo ao final da lista
        nodo->conecta(&guarda);

        len++;
    }

    // DONE
    template<typename T> void lista<T>::anexatodos(const lista <T> &dados) {

        // quando a lista passada está vazia nada é feito.
        if (dados.len == 0) return;

        // cria nodo ptr que aponta para o primeiro nodo da lista dados
        Nodo *ptr = dados.guarda.proximo;

        // enquanto o ptr for diferente do ultimo nodo da lista dados
        while (ptr != dados.guarda.anterior) {


            // criamos um nodo que contem os dados do nodo ptr
            auto nodo = new Nodo(ptr->dado);
            // conectamos o nodo criado na lista
            nodo->conecta(&guarda);
            // aumentamos o tamanho da lista em 1
            len++;
            // ptr agora é igual ao próximo nodo da lista dados
            ptr = ptr->proximo;

        }

        // Adiciona no final da lista o último nodo (ou o único nodo, se for uma lista de apenas um dado)
        auto nodo = new Nodo(ptr->dado);
        nodo->conecta(&guarda);
        len++;
    }

    // DONE
    template<typename T> int lista<T>::comprimento() const {
        return len;
    }

    // DONE
    template<typename T> void lista<T>::esvazia() {

        // caso a lista esteja vazia, nada é feito.
        // enquanto a lista não estiver vazia, removemos o ultimo dado da lista.
        while (!vazia()) {
            remove(len - 1);
        }
    }



    // DONE
    template<typename T> T &lista<T>::obtem(unsigned int posicao) const {

        // se posição não existir na lista cria uma exceção.
        if (posicao < len) {
            Nodo *ptr = obtemNodo(posicao);
            // acessa o dado do ptr
            return ptr->dado;
        }
        else throw -1;
    }

    // DONE
    template<typename T> T &lista<T>::operator[](int pos) const {
        return obtem(pos);
    }

    // DONE
    template<typename T> void lista<T>::escrevaSe(std::ostream &out) const {
        // usa como base a função escrevaSe completa
        escrevaSe(out, "\n");
    }

    // DONE
    template<typename T> void lista<T>::escrevaSe(std::ostream &out, const std::string &delim) const {

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

    // DONE
    template<typename T> T lista<T>::remove(int posicao) {
        // se a posição dada não é uma posição valida na lista (maior que o tamanho dela)
        if (posicao >= len) throw -1;
        else {
            // obtem o valor do nodo na posicao x
            Nodo *ptr = obtemNodo(posicao);
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

    // DONE
    template<typename T> void lista<T>::retira(const T &algo) {
        // criamos um ponteiro para o primeiro nodo da lista
        Nodo * ptr = guarda.proximo;

        // enquanto ptr não for igual ao ultimo nodo da lista
        while (ptr != guarda.anterior) {
            // se o dado do ponteiro for igual a algo desconecta-se o nodo e diminui o tamanho da lista.
            if (ptr->dado == algo) {
                ptr = ptr->proximo;
                ptr->anterior->desconecta();
                len--;
                // se o dado do nodo atual não é igual a algo, apenas continuamos a percorrer a lista.
            } else {
                ptr = ptr->proximo;

            }
        }

        // testa se o último (e/ou único) nodo da lista é igual a algo
        if (ptr->dado == algo) {
            ptr->desconecta();
            len--;
        }
    }

    // DONE
    template<typename T> bool lista<T>::vazia() const {
        return len == 0;
    }

    // DONE
    template<typename T> void lista<T>::insereOrdenado(const T &algo) {
        Nodo * ptr = guarda.proximo;

        // Enquanto ptr for diferente de guarda
        while (ptr != &guarda) {
            // se o dado do ptr for menor que algo, continua a percorrer a lista
            if (ptr->dado < algo) {
                ptr = ptr->proximo;
                // se dado não for menor que o algo, ele é igual ou maior. Criamos um novo nodo e conectamos ele ao ptr.
            } else {
                auto nodo = new Nodo(algo);
                nodo->conecta(ptr);
                len++;
                return;
            }
        }
        // Quando todos os dados da lista são menores que algo adiciona algo no final da lista;
        auto nodo = new Nodo(algo);
        nodo->conecta(&guarda);
        len++;
    }

    // DONE
    template<typename T> void lista<T>::ordena() {
        // algoritmo de ordenamento bolha!
        // inicialmente já excluimos listas que não possuem mais de 2 nodos.
        if (len < 2) return;

        auto nodo = &guarda;

        for (Nodo *j = guarda.anterior; j != guarda.proximo; j = j->anterior) {
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

    // DONE
    template<typename T> T &lista<T>::procura(const T &algo) const {
        Nodo * ptr = guarda.proximo;

        // enquanto ptr não for igual ao ultimo nodo da lista
        while (ptr != &guarda) {
            // se o dado do ponteiro for igual a algo .
            if (ptr->dado == algo) {
                return ptr->dado;
                // se o dado do nodo atual não é igual a algo, apenas continuamos a percorrer a lista.
            } else {
                ptr = ptr->proximo;
            }
        }

        throw -1;
        // se não achar dado, cria exceção
    }

    // DONE
    template<typename T> lista <T> &lista<T>::procuraMuitos(const T &algo, lista <T> &lista) const {
        Nodo * ptr = guarda.proximo;
        //lista.esvazia();
        // enquanto ptr não for igual ao ultimo nodo da lista

        while (ptr != &guarda) {
            // se o dado do ponteiro for igual a algo, anexamos algo a lista.
            if (ptr->dado == algo) {
                lista.anexa(algo);
            }
            ptr = ptr->proximo;
        }
    }

    // DONE
    template<typename T> lista <T> &lista<T>::operator=(const lista <T> &outra) {

        esvazia();

        Nodo *ptr = outra.guarda.proximo;

        // enquanto a lista nova for menor que a outra lista, criamos um nodo, copiamos o próximo nodo da lista e conectamos este novo nodo ao anterior.
        while (len < outra.len) {
            // criamos um nodo com o conteudo do proximo nodo da lista de origem
            auto nodo = new Nodo(ptr->dado);
            // conectamos o nodo criado ao ultimo nodo da lista nova
            nodo->conecta(&guarda);
            // tamanho da lista aumenta
            ptr = ptr->proximo;
            len++;
        }

        // a func retorna uma referencia a lista que a chamou.
        return *this;
    }

    // DONE
    template<typename T> bool lista<T>::operator==(const lista <T> &outra) const {

        if (len != outra.len) {
            return false;
        } else {
            Nodo *outraptr = outra.guarda.proximo;
            Nodo *ptr = guarda.proximo;

            while (ptr != &guarda) {
                if (ptr->dado != outraptr->dado) {
                    return false;
                }
                ptr = ptr->proximo;
                outraptr = outraptr->proximo;
            }
            return true;
        }
    }

    // DONE
    template<typename T> void lista<T>::inverte() {
        // se a lista for menor que dois, não precisamos inverter nada.
        if (len < 2) return;
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

    // DONE
    template<typename T> bool lista<T>::inicio() const {
        return atual == &guarda;

    }

    // DONE
    template<typename T> bool lista<T>::fim() const {
        // se o nodo atual na iteração for igual ao guarda (primeiro nodo) a iteração chegou ao final.
        return atual == &guarda;
    }

    // DONE
    template<typename T> void lista<T>::inicia() {
        // nesse caso, guarda.proximo é o primeiro nodo da lista.
        atual = guarda.proximo;
    }

    // DONE
    template<typename T> void lista<T>::iniciaPeloFim() {
        atual = guarda.anterior;
    }

    //DONE
    template<typename T> T &lista<T>::proximo() {

        if (fim()) throw -1;

        // atual foi setado na função inicia().
        // Aqui damos o valor do atual para o dado a ser retornado e mudamos o valor de atual para o próximo dado.
        T &dado = atual->dado;
        atual = atual->proximo;

        return dado;
    }

    // DONE
    template<typename T> T &lista<T>::anterior() {

        if (fim()) throw -1;

        // basicamente o mesmo que o proximo, mas em vez de mudar o valor do nodo atual para o proximo nodo, mudaremos para o nodo anterior.
        T &dado = atual->dado;
        atual = atual->anterior;

        return dado;
    }

    // DONE
    template<typename T> lista <T> &lista<T>::sublista(unsigned int pos1, unsigned int pos2, lista <T> &outra) const {
        // Para ser uma sublista válida, a pos2 tem q ser maior e diferente da pos1.
        if (pos2 < pos1 or pos1 > len) throw -1;
        // Para ser uma sublista valida, a posição inicial precisa estar dentro da lista (menor que len).

        // se a pos2 extrapolar o fim da fila, tornamos pos2 = len para facilitar o codigo.
        if (pos2 > len) {
            pos2 = len;
        }

        while (pos1 <= pos2) {

            auto nodo = obtemNodo(pos1);
            outra.anexa(nodo->dado);
            pos1++;
        }

    }

    template<typename T> lista <T> *lista<T>::sublista(unsigned int pos1, unsigned int pos2) const {

    }

    // DONE
    template<class T> void lista<T>::embaralha() {

        // Criamos uma variável static para usar a mesma seed enquanto o programa estiver rodando
        static bool started = false;

        if (! started) {
            started = true;
            srand(clock());
        }

        // se o tamanho da lista é menor q 2 não precisamos embaralhar.
        if (len < 2) return;

        int i = len - 1;
        // embaralha cada um dos itens da lista usando um número aleatório para fazer as trocas de posições.
        while (i > 0) {
            int j = rand() % (i + 1);
            if (i != j) {
                T &dado1 = obtem(j);
                T &dado2 = obtem(i);
                T aux = dado1;
                dado1 = dado2;
                dado2 = aux;
            }
            i--;
        }

    }

}// fim namespace

#endif	/* LISTA_IMPL_H */