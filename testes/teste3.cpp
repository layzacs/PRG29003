#include <string>
#include <iostream>
#include <prglib.h>
#include <fstream>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
    ifstream arquivo(argv[1]);

    pilha<int> numeros(2000); // declarando a pilha com valor alto

    int num;

    while (arquivo >> num) { // usando o ">>" para pegar a próxima informação do arquivo e colocar na variável num (eu nunca tinha visto isso na minha vida, professor! Foi bem complicado de achar na internet.)

        // no primeiro num, a pilha estará vazia! vamos apenas colocar o numero dentro dela.
        if (numeros.vazia()) {
            numeros.push(num);
        }
        // quando o número da vez for menor que o número do topo da pilha, sabemos que o topo da pilha é um número de pico. imprimimos na tela com um espaço para dividí-los.
        else if (num < numeros.top()) {
        cout << ' ' << numeros.top() ;
        numeros.push(num);
        }
        // quando o número da vez é maior que o topo da pilha, sabemos que o topo da pilha não é um pico. Salvamos o número e vamos pro próximo.
        else if (num > numeros.top()) {
            numeros.push(num);
        }
    }
}
