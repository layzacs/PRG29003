#include <iostream>
#include <prglib.h>
#include <cstdlib>
#include <time.h>

using namespace std;
using prglib::lista;

int main() {

    lista<int> l;

    srand (time(NULL));

    for (int i=0;i<10;i++) {
        int num = 1 + (rand() % 10);
        l.anexa(num);
    }
    l.escrevaSe(cout, ",");

}
