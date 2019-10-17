#include <iostream>
#include <prglib.h>
#include <fstream>
#include <string>

using namespace prglib;
using namespace std;


int main() {

    ifstream arq("cliente.txt");

    thash<float> clientes(1000);

    if (!arq.is_open()) {
        cout << "Arquivo Invalido" << endl;
        throw -1;
    }

    string linha;
    string nome_final;
    string mes_final;
    string custo_final;
    int j = 0;

    getline(cin, nome_final);
    getline(cin, mes_final);


    while (getline(arq, linha)) {

        string custos;
        float custo;
        string mes;
        string nome;


        int found = linha.find('/');
        int last_found = linha.find_last_of('/');

        mes = linha.substr(found+1, last_found - found -1);

        found = linha.find(' ');
        last_found = linha.find(' ', found+1);

        custos = linha.substr(found, (last_found - found));
        custo = stof(custos);

        nome = linha.substr(last_found+1);

        if (clientes.existe(nome) && mes == mes_final) {

            clientes[nome] = clientes[nome] + custo;
        } else if (mes == mes_final) {
            j++;
            clientes.adiciona(nome, custo);
        }

    }

    if (j == 0 ) {
        cout << "mes invalido" << endl;
    }
    if (clientes.existe(nome_final)) {
        cout << clientes[nome_final] << endl;
    } else {
        cout << "sem compras no mes" << endl;
    }

}
