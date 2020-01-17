#include <iostream>
#include <fstream>
#include <prglib.h>

using namespace std;

using prglib::arvore;
using prglib::lista;

/*
 *
 */
int main(int argc, char** argv) {
    ifstream inp("../tree.txt");
    auto a = new arvore<int>(inp);

    cout << "Valor da raiz: " << a->obtem() << endl;
    cout << "Valor: " << a->obtem(5) << endl;

    lista<int> l;
    a->listeInOrder(l);

    cout << "Dados ordenados: ";
    l.escrevaSe(cout, ", ");
    cout << endl;

    auto diagrama = desenha_arvore(a);

    ofstream diag("tree.dot");
    diag << diagrama;
    diag.close();

    return 0;
}
