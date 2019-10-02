#include <iostream>
#include <prglib.h>

using namespace std;

using prglib::arvore;
using prglib::lista;

/*
 *
 */
int main(int argc, char** argv) {

    // 10 é o valor da raiz, ele é passado primeiramente. A árvore nunca fica vazia
    // é importante que a raiz seja um valor mediano, no caso, a letra m está perto do centro do alfabeto.
    arvore<int> * a = new arvore<int>(10);

    // todo valor que é acrescentado procura automaticamente o lugar certo para estar
    // Valores repetidos são sobrescritos na implementação da prglib
    a->adiciona(5);
    a->adiciona(7);
    a->adiciona(2);
    a->adiciona(13);
    a->adiciona(11);
    a->adiciona(15);

   cout << "Valor da raiz" << a->obtem() << endl;

    lista<int> l;
    // cria uma lista com os dados da árvore em ordem. Neste caso, de menor número para maior número
    a->listeInOrder(l);

    cout << "In-order: ";
    l.escrevaSe(cout, ", ");
    cout << endl;

    // tem que destruir a arvore após a necessidade dela, ela não se destroi sozinha
    delete a;

    return 0;
}
