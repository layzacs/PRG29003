#include <prglib.h>
#include <string>
#include <iostream>

using prglib::arvore;
using namespace std;

int main() {
    arvore<int> * arv = new arvore<int>(5);

    arv->adiciona(4);
    arv->adiciona(3);
    arv->adiciona(2);
    arv->adiciona(1);
    arv->adiciona(0);

    // a arvore "arv" está totalmente desbalanceada, tendo todos os nodos do lado esquerdo
    // Mostra seu fator de balanceamento e sua altura
    cout << "Altura: " << arv->altura() << endl;
    cout << "Fator de balanceamento: " << arv->fatorB() << endl;

    // balanceia a arvore
    arv = arv->balanceia();

    // Mostra novamente seu fator de balanceamento e sua altura
    cout << "Altura: " << arv->altura() << endl;
    cout << "Fator de balanceamento: " << arv->fatorB() << endl;

    // destroi a arvore
    delete arv;
}
