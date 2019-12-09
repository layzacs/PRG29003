#ifndef PILHA_H
#define	PILHA_H

namespace prglib {

    template <typename T> class pilha {
    public:
        // construtor: deve-se informar a capacidade da pilha
        pilha(unsigned int umaCapacidade);

        // construtor de cópia: cria uma pilha que é cópia de outra
        pilha(const pilha<T>& outra);

        // destrutor da pilha
        ~pilha();

        // operador de atribuição: torna esta pilha uma cópia de outra pilha
        pilha<T> & operator=(const pilha<T> & outra);

        // operações da pilha

        virtual void push(const T & dado); // empilha um dado

        T pop(); // desempilha um dado

        virtual const T& top() const; // retorna o dado do topo da pilha, sem retirá-lo

        bool vazia() const;
        bool cheia() const;
        unsigned int comprimento() const;
        void esvazia();
        unsigned int capacidade() const;

    private:
        // Topo da pilha (corresponde também à qtde de dados na pilha)
        unsigned int topo;

        // Capacidade da pilha (quantos dados cabem nela)
        unsigned int cap;

        // a área de memória onde são armazenados os dados (um vetor)
        T * buffer;
    };

} // fim do namespace

#endif	/* PILHA_H */

