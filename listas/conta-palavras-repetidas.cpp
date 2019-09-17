#include <string>
#include <prglib.h>
#include <iostream>

using namespace std;
using namespace prglib;

struct a {
    string word;
    int rec=0;
};

int main(int argc, char * argv[]) {
    ifstream arquivo(argv[1]);
    string word;
    lista<struct a> l;


    while (arquivo >> word) {

        int i=0;

        l.inicia();

        while (!l.fim()) {
            struct a &aux = l.proximo();
            if (aux.word == word) {
                aux.rec++;
                i++;
                break;
            }
        }
        if (i == 0) {
            struct a aux;
            aux.word = word;
            aux.rec++;
            l.anexa(aux);
        }
    }

    l.inicia();
    while(!l.fim()) {
        struct a aux = l.proximo();
        cout << aux.word << ' ' << aux.rec << endl;
    }

}
