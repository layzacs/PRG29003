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


    template <typename T> const T& arvore<T>::obtemMenor() const {
    const arvore<T> * atual = this;   // aqui temos q chamar como const pq a função é const, significando que ela não modifica em momento nenhum a árvore.
    while (atual->esq != nullptr) {
        atual = atual->esq;
    }

    return atual->data;

}

    template <typename T> const T& arvore<T>::obtemMaior() const {
    const arvore<T> * atual = this;   // aqui temos q chamar como const pq a função é const, significando que ela não modifica em momento nenhum a árvore.
    while (atual->dir != nullptr) {
        atual = atual->dir;
    }

    return atual->data;

}


    template <typename T> const T& arvore<T>::obtem() const {
    return data;
}

    template <typename T> void arvore<T>::listeEmLargura(lista<T> & result) {
    lista<arvore<T>*> nodos;

    nodos.anexa(this);

    while (!nodos.vazia()) {
        auto node = nodos.remove(0);
        result.anexa(node->data);

        if (node->esq != nullptr) {
            nodos.anexa(node->esq);
        }
        if (node->dir != nullptr) {
            nodos.anexa(node->dir);
        }
    }
}

    template <typename T> void arvore<T>::listeInOrder(lista<T> & result) {
    // lista em ordem a arvore feita de forma recursiva
    if (esq != nullptr) {
        esq->listeInOrder(result);
    }

    result.anexa(data);

    if (dir != nullptr) {
        dir->listeInOrder(result);
    }

}

    template <typename T> void arvore<T>::listePreOrder(lista<T> & result) {

    // não recursivo
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

    /*/ recursivo
    result.anexa(data);

    if (esq != nullptr) {
        esq->listePreOrder(result);
    }

    if (dir != nullptr) {
        dir->listePreOrder(result);
    }
*/

}

    template <typename T> void arvore<T>::listePostOrder(lista<T> & result) {

    if (esq != nullptr) {
        esq->listePostOrder(result);
    }

    if (dir != nullptr) {
        dir->listePostOrder(result);
    }

    result.anexa(data);
}

    template <typename T> unsigned int arvore<T>::tamanho() const {
    }

    template <typename T> int arvore<T>::fatorB()  {
    int altdir=0, altesq = 0;
    //
    if (esq != nullptr) {
        altesq = 1 + esq->altura();
    }

    if (dir != nullptr) {
        altdir = 1 + dir->altura();
    }

    return (altesq - altdir);

}

    template <typename T> unsigned int arvore<T>::altura()  {
    unsigned int altdir=0, altesq = 0;
    // altura da arvore feita de forma recursiva
    if (esq != nullptr) {
        altesq = 1 + esq->altura();
    }

    if (dir != nullptr) {
        altdir = 1 + dir->altura();
    }

    if (altesq > altdir) return altesq;
    return altdir;

}

    template <typename T> arvore<T> * arvore<T>::rotacionaL() {
    arvore<T> * n1 = this;
    arvore<T> * n2 = dir;
    arvore<T> * b = n2->esq; // subarvore da esquerda do n2

    n2->esq = n1;
    n1->dir = b;

    return n2;

}

    template <typename T> arvore<T> * arvore<T>::rotacionaR() {
    arvore<T> * n1 = this;
    arvore<T> * n2 = esq;
    arvore<T> * b = n2->dir; // subarvore da direita

    n2->dir = n1;
    n1->esq = b;

    return n2;

}


    template <typename T> arvore<T>* arvore<T>::balanceia() {

    if (esq != nullptr) {
        esq = esq->balanceia();
    }

    if (dir != nullptr) {
        dir = dir->balanceia();
    }

    auto raiz = this;

    while (raiz->fatorB() < -1) {

        if (raiz->dir->fatorB() > 0) {
            raiz->dir = raiz->dir->rotacionaR();
        }
        raiz = raiz->rotacionaL();
    }



    while (raiz->fatorB() > 1) {

        if (raiz->esq->fatorB() < 0) {
            raiz->esq = raiz->esq->rotacionaL();
        }
        raiz = raiz->rotacionaR();
    }

    return raiz;
}

    template <typename T> arvore<T>* arvore<T>::balanceia(bool otimo) {
    }

    template <typename T> void arvore<T>::inicia() {
    if (p_stack == nullptr) p_stack = new lista<arvore<T>*>;
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

    template <typename T> void arvore<T>::obtemMenoresQue(lista<T> & result, const T & algo) {
}

    template <typename T> void arvore<T>::obtemMaioresQue(lista<T> & result, const T & algo) {
    }

    template <typename T> void arvore<T>::obtemIntervalo(lista<T>& result, const T& start, const T& end) {
    // pega todos os parametros entre star e end, INCLUSIVE o start e o end.

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

