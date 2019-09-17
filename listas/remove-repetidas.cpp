#include <fstream>
#include <iostream>
#include <string>
#include <prglib.h>

using namespace std;
using prglib::lista;

int main(int argc, char * argv[]) {
    ifstream arquivo(argv[1]);
    string word;
    lista<string> l;


    while (arquivo >> word) {
        int i=0;
        l.inicia();
        while (!l.fim()) {
            if (l.proximo() == word) {
                i++;
                break;
            }
        }
        if (i == 0) {
            l.anexa(word);
        }
    }
    l.escrevaSe(cout, " ");
}
