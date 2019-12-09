#include <iostream>
#include <string>
#include <prglib.h>

using namespace std;
using prglib::arvore;
using prglib::lista;
int main() {

    // Uma árvore deve ser criada dinamicamente ... isso facilita
    // sua implementação.
    arvore<int> * arv = new arvore<int>(1);


    arv->adiciona(2);
    arv->adiciona(3);
    arv->adiciona(4);

    arv->adiciona(5);

    arv->adiciona(6);

    arv->adiciona(7);

    arv->escrevaSe(cout);
    cout << "raiz = " << arv->obtem() << endl;
    cout << "fatorb = " << arv->fatorB() << endl;

    cout << "primeiro balanceamento" << endl;

    arv = arv->balanceia();

    cout << "raiz = " << arv->obtem() << endl;
    cout << "fatorb = " << arv->fatorB() << endl;

    arv->escrevaSe(cout);

    cout << "segundo balanceamento" << endl;

    cout << "raiz = " << arv->obtem() << endl;

    cout << "fatorb = " << arv->fatorB() << endl;

    arv = arv->balanceia();

    cout << "fatorb = " << arv->fatorB() << endl;
    cout << "raiz = " << arv->obtem() << endl;

    arv->escrevaSe(cout);

    delete arv;

    return 0;
}