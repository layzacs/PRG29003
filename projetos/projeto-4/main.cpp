//**********************************************************************************************************************;
// Project           : Dicionário lingua portuguesa
//
// Author            : layzacs
//
//
// Date created      : 15102019
//
//**********************************************************************************************************************;

#include "verbete.h"

int main() {
    int i;
    cout << "Dicionário da Lingua Portuguesa" << endl;
    Verbete a;
    string teste;
    ifstream arq("../data/verbetes.txt");
    if (! arq.is_open()) {
        cout << "Arquivo de dicionário Inválido." << endl;
        exit(0);
    }

    while (true) {

        cout << "Escolha entre as opções: \n1 - Preparar o dicionário.\n2 - Buscar verbete.\n";
        cin >> i;
        cin.ignore();

        switch (i) {

            case 1: {

                a = cria_verbete(arq);
                cout << "Verbete criado." << endl;
                cout << a.palavra << endl;
                cout << a.classe_gramatical << endl;
                a.significados.escrevaSe(cout, "\n");
                cout << endl;
                break;

            }

            default:
                exit(0);
        }
    }

}