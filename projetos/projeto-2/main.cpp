//**********************************************************************************************************************;
// Project           :
//
// Author            : layzacs
//
//
// Date created      : 06082019
//
// Purpose           : Programa para calcular a distância de um ator até Kevin Bacon, mostrando o caminho usado na
//                     pesquisa.
//
//                     Funcionalidades
//
//
//
// Revision History  :
//
// Date          Author      Ref    Revision (Date in YYYYMMDD format)
// 04082019      layzacs     1      Reformulada a função busca_bfs.
// 06082019      layzacs     1      Criada a função busca_dfs.
// 06082019      layzacs     1      Modificado nome de variáveis para denotar parentesco.
//**********************************************************************************************************************;
#include <iostream>
#include "proc.h"
#include <prglib.h>
#include <string>

using namespace std;
using namespace prglib;

int main() {
    lista<filmes> teste;

    teste = obtem_dados("../data/dados.txt");
    string ator_teste = "Will Smith";

    lista<string> filmes_ator = obtem_filmes(ator_teste, teste);
    cout << "Filmes do ator " << ator_teste << ":" << endl;
    filmes_ator.escrevaSe(cout, ", ");
}