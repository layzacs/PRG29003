#include <iostream>
#include <string>
#include <prglib.h>

using prglib::lista;

using namespace std;

int main() {

    lista<string> list;
    lista<string> lista;



    list.anexa("b");
    list.anexa("b");
    list.anexa("a");
    list.anexa("a");
    list.anexa("b");

    lista = list;

    if (list == lista) {
        cout << "BIRIRIRIRIRIRI" << endl;
    }

return 0;

}