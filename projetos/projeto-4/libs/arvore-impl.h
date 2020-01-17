/* 
 * File:   arvore-impl.h
 * Author: sobral
 *
 * Created on 8 de Outubro de 2016, 19:37
 */

#ifndef ARVORE_IMPL_H
#define	ARVORE_IMPL_H

#include "arvore.h"

namespace prglib {

    // TODO: implementar destrutor
    template <typename T> arvore<T>::~arvore() {
    }
    
    template <typename T> arvore<T>::arvore() {
    }

    // DONE
    template <typename T> arvore<T>::arvore(const T & dado) {
        // iniciamos os valores da nova árvore
        data = dado;
        pai = this; // pai aponta para ele mesmo
        esq = nullptr;
        dir = nullptr;
    }

    // DONE
    template<typename T> arvore<T>::arvore(const arvore <T> &outra) {
        // inicialmente copiamos a raiz da outra árvore para a nova
        data = outra->data;

        // criamos recursivamente cada uma das subarvores, para a esquerda e direita
        if (outra->esq != nullptr) {
            esq = new arvore<T>(outra->esq);
        }
        else esq = nullptr;

        if (outra->dir != nullptr) {
            dir = new arvore<T>(outra->dir);
        }
        else dir = nullptr;

    }

    // DONE
    template <typename T> arvore<T>::arvore(istream &inp) {
        string dado;

        // inicialmente adicionamos a raiz da árvore (primeiro dado do arquivo)
        inp >> dado;
        data = dado;

        // enquanto houver dados no arquivo, eles são adicionados a arvore
        while (inp >> dado) {
            adiciona(dado);
        }
    }

    // DONE
    template <typename T> arvore<T>::arvore(prglib::lista<T> &dados) {
        //se lista vazia retorna exceção
        if (dados.vazia()) throw -1;

        dados.inicia();

        data = dados.proximo();

        // dados adicionados por meio de iteração da lista.
        while (! dados.fim()) {
            adiciona(dados.proximo());
        }
    }

    // DONE
    template <typename T> void arvore<T>::adiciona(const T & algo) {
        arvore<T> *atual = this; // define um nodo apontando para a raiz da arvore

        while (true) {
            // se o dado já está dentro da árvore, dado é sobrescrito.
            if (algo == atual->data) {
                atual->data = algo;
                return;
            }
            // se algo for menor que o valor do nodo atual, ele precisa ser inserido para a esquerda, percorremos os dados da esquerda até encontrar um nullptr.
            if (algo < atual->data) {
                if (atual->esq != nullptr) {
                    atual = atual->esq;

                } else {
                    // após achado um nullptr, criamos uma nova árvore (que vira subarvore) e apontamos o nodo atual como pai.
                    auto novo = new arvore<T>(algo);
                    atual->esq = novo;
                    novo->pai = atual;
                    return;
                }
            } else {
                // se algo for maior que o nodo atual, fazemos o mesmo processo de quando ele é menor mas agora caminhando para a direita do nodo atual.
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

    // DONE
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

/*
template <typename T> const T& arvore<T>::obtem_sucessor(const T & algo) const {

    const arvore<T> * atual = this;

    if (atual == algo && dir == nullptr) {
        throw -1
    }

        if (atual == algo && atual->dir != nullptr) {
            return atual->dir;
        }

        if (atual < algo) {
            atual = atual->dir;
            atual->obtem_sucessor(algo);

        }

        if (atual > algo) {
            atual = atual->esq;
            atual->obtem_sucessor(algo);
        }

        //  return succ;


    }
*/


    // DONE
    template <typename T> const T& arvore<T>::obtemMenor() const {
        const arvore<T> *atual = this;   // aqui temos q chamar como const pq a função é const, significando que ela não modifica em momento nenhum a árvore.
        while (atual->esq != nullptr) {
            atual = atual->esq;
        }

        return atual->data;

    }

    // DONE
    template <typename T> const T& arvore<T>::obtemMaior() const {
        const arvore<T> *atual = this;   // aqui temos q chamar como const pq a função é const, significando que ela não modifica em momento nenhum a árvore.
        while (atual->dir != nullptr) {
            atual = atual->dir;
        }

        return atual->data;

    }


    // DONE
    template <typename T> const T& arvore<T>::obtem() const {
        // retorna o valor da raiz.
        return data;
}

    // DONE
    template <typename T> void arvore<T>::listeEmLargura(lista<T> & result) {
        // criada lista para comportar todos os nodos
        lista<arvore<T>*> nodos;

        // o nodo atual é anexado
        nodos.anexa(this);

        // enquanto a lista de nodos não estiver sozinha, checa se esquerda e direita não são nullptr e adiciona-os a lista
        while (!nodos.vazia()) {
            auto node = nodos.remove(0);
            // dado do nodo é anexado a lista de resultados
            result.anexa(node->data);

            if (node->esq != nullptr) {
                nodos.anexa(node->esq);
            }
            if (node->dir != nullptr) {
                nodos.anexa(node->dir);
            }
        }
    }

    // DONE
    template <typename T> void arvore<T>::listeInOrder(lista<T> & result) {
    // lista em ordem a arvore feita de forma recursiva
    // seguindo esquerda -> raiz -> direita
    // inicialmente checa se possui nodo na esquerda e chama recursivamente a função
    if (esq != nullptr) {
        esq->listeInOrder(result);
    }

    //quando nodo da esquerda for um nullptr, anexa o dado na lista. depois chama recursivamente nna direita.
    result.anexa(data);

    if (dir != nullptr) {
        dir->listeInOrder(result);
    }

}

    // DONE
    template <typename T> void arvore<T>::listePreOrder(lista<T> & result) {

        /* // não recursivo
        lista<arvore<T>*> nodos;

        nodos.anexa(this);

        while (!nodos.vazia()) {
            auto node = nodos.remove(0);
            result.anexa(node->data);

            if (node->dir != nullptr) {
                nodos.insere(node->dir);
            }

            if (node->esq != nullptr) {
                nodos.insere(node->esq);
            }

        }
        */
        // recursivo
        // anexa dado na lista
        result.anexa(data);
        // se esquerda não é nullptr, chama recursivamente a função
        if (esq != nullptr) {
            esq->listePreOrder(result);
        }
        // se direita não é nullptr, chama recursivamente a função
        if (dir != nullptr) {
            dir->listePreOrder(result);
        }
    }

    // DONE
    template <typename T> void arvore<T>::listePostOrder(lista<T> & result) {
    // esquerda -> direita -> raiz
    // muito parecido com InOrder, mas anexamos o dado no final da função, fazendo com que fique em outra ordem.
    if (esq != nullptr) {
        esq->listePostOrder(result);
    }

    if (dir != nullptr) {
        dir->listePostOrder(result);
    }

    result.anexa(data);
}

    // DONE
    template <typename T> unsigned int arvore<T>::tamanho() const {
        unsigned int tam=0;

        // se esquerda não é nullptr, chamamos a função na esquerda
        if (esq != nullptr) {
            tam = tam + esq->tamanho();
        }

        // se direita não é nullptr, chamamos a função na direita
        if (dir != nullptr) {
            tam = tam + dir->tamanho();
        }
        // Antes de retornar pra chamada anterior da função incrementa o tamanho (vai ser incrementado, assim, em cada um dos nodos).
        tam++;
        return tam;


    }

    // DONE
    template <typename T> int arvore<T>::fatorB() {

        int altdir = 0, altesq = 0;
        // se nodo da esquerda não for nullptr, incrementa altura e chama função recursivamente
        if (esq != nullptr) {
            altesq = 1 + esq->altura();
        }

        // se nodo da direita0 não for nullptr, incrementa altura e chama função recursivamente
        if (dir != nullptr) {
            altdir = 1 + dir->altura();
        }

        // retorna a subtração dos dois valores para ver a diferença de tamanho.
        return (altesq - altdir);
    }

    // DONE
    template <typename T> unsigned int arvore<T>::altura() {
        unsigned int altdir = 0, altesq = 0;
        // altura da arvore feita de forma recursiva
        // Se esquerda diferente de nullptr incrementa altura da esquerda e chama a função recursivamente
        if (esq != nullptr) {
            altesq = 1 + esq->altura();
        }

        if (dir != nullptr) {
            altdir = 1 + dir->altura();
        }

        // após percorrer todos os nodos e chegar nas folhas, retorna o maior valor.
        if (altesq > altdir) return altesq;
        return altdir;
    }

    // DONE
    template <typename T> arvore<T> * arvore<T>::rotacionaL() {
    arvore<T> * n1 = this;     // nodo atual
    arvore<T> * n2 = dir;      // nodo direito do n2
    arvore<T> * b = n2->esq;   // subarvore da esquerda do n2

    n2->esq = n1;              // n1 (inicialmente a raiz da árvore) passa a ser o nodo esquerdo de n2
    n1->dir = b;               // tudo que estava na esquerda do n2 é conectado na direita do n1

    return n2;

}

    // DONE
    template <typename T> arvore<T> * arvore<T>::rotacionaR() {
    arvore<T> * n1 = this;    // nodo atual
    arvore<T> * n2 = esq;     // nodo esquerdo do n2
    arvore<T> * b = n2->dir;  // subarvore da direita do n2

    n2->dir = n1;             // n1 (inicialmente a raiz da árvore) passa a ser o nodo direito de n2
    n1->esq = b;              // tudo que estava na direita do n2 é conectado na esquerda do n1

    return n2;

}

    // DONE
    template <typename T> arvore<T>* arvore<T>::balanceia() {
        // chama recursivamente a função até chegar nas folhas.
        if (esq != nullptr) {
            esq = esq->balanceia();
        }

        if (dir != nullptr) {
            dir = dir->balanceia();
        }

        // definimos a raiz como nodo atual
        auto raiz = this;

        // enquanto o fator de balanceamento calculado for menor que -1
        while (raiz->fatorB() < -1) {
            // se fator de potencia da subarvore direita for maior que 0 rotaciona pra direita
            if (raiz->dir->fatorB() > 0) {
                raiz->dir = raiz->dir->rotacionaR();
            }
            // rotaciona pra esquerda
            raiz = raiz->rotacionaL();
        }

        // se o fator de potencia for maior que 1
        while (raiz->fatorB() > 1) {
            //se subarvore da esquerda tiver fator de balanceamento menor que 0 rotaciona pra esquerda
            if (raiz->esq->fatorB() < 0) {
                raiz->esq = raiz->esq->rotacionaL();
            }
            // rotaciona pra direita
            raiz = raiz->rotacionaR();
        }

        return raiz;
    }

    // TODO: Implementar
    template <typename T> arvore<T>* arvore<T>::balanceia(bool otimo) {
        // definimos raiz como nodo atual
        auto raiz = this;

        // chamamos balanceia pelo menos uma vez.
        raiz->balanceia();

        // vamos executar a função balanceia até que o fatorb da raiz pare de mudar.
        // se fb_novo = 0 não precisamos balancear a árvore

        int fb_anterior = 0, fb_novo = raiz->fatorB();

        while (fb_anterior != fb_novo) {
            fb_anterior = fb_novo;
            raiz->balanceia();
            fb_novo = raiz->fatorB();
        }
        // retornamos a árvore modificada.
        return raiz;
    }

    template <typename T> void arvore<T>::inicia() {
        if (p_stack == nullptr) p_stack = new lista<arvore<T> *>;
        else p_stack->esvazia();

        // versão inicial: pre order
        p_stack->insere(this);
    }

    template <typename T> T& arvore<T>::proximo() {
        if (fim()) throw -1;

        auto node = p_stack->remove(0);

        if (node->dir != nullptr) {
            p_stack->insere(node->dir);
        }

        if (node->esq != nullptr) {
            p_stack->insere(node->esq);
        }

        return node->data;
    }

    template <typename T> bool arvore<T>::fim() {
    return p_stack->vazia();
}
    // TODO: Implementar
    template <typename T> void arvore<T>::obtemMenoresQue(lista<T> & result, const T & algo) {
}

    // TODO: Implementar
    template <typename T> void arvore<T>::obtemMaioresQue(lista<T> & result, const T & algo) {
    }

    template <typename T> void arvore<T>::obtemIntervalo(lista<T>& result, const T& start, const T& end) {
        // pega todos os parametros entre start e end, INCLUSIVE o start e o end.

        auto raiz = this;

        if (raiz < start) {
            dir->obtemIntervalo(result, start, end);
        }

        if (raiz > start) {
            esq->obtemIntervalo(result, start, end);
        }
    }

    // mostra formato atual da arvore
    // by msobral
    template <typename T> void arvore<T>::escrevaSe(ostream& out) const {
        static int nivel = -1;
        string prefixo;

        nivel++;
        prefixo.append(nivel, ' ');

        if (dir) dir->escrevaSe(out);
        out << prefixo << data << std::endl;
        if (esq) esq->escrevaSe(out);
        nivel--;
    }



};

#endif	/* ARVORE_IMPL_H */


