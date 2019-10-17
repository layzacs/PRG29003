// Padrão
#include <string>
#include <prglib.h>

using namespace std;
using namespace prglib;

int main() {
}

//********** para quando o nome do arquivo ou parametro for passado pela linha de comando
#include <string>
#include <prglib.h>
#include <fstream>
#include <iostream>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
    ifstream arquivo(argv[1]);
    string word;
    string linha;

    // Testa se arquivo abriu;
    if (! arq.is_open()) {
        cout << "msg de erro" << endl;
    }
    // para pegar uma palavra do arquivo
    while (arquivo >> word) {
    }
    // para pegar toda a linha do arquivo
    while (getline(cin, linha)) {

    }
