//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"

vector<string> roda(const string & cmd) {
    Terminal term(cmd);

    auto res = term.lePalavras();
    return res;
}

void verifica(int n) {
    string num = to_string(n);
    string arq = "cat ../data/res"+num+".txt";
    string arqres = PROG;
    arqres += " ../data/arq"+num+".txt";

    auto v = roda(arq);
    auto res = roda(arqres);

    if (v != res) {
        FAIL() << "Esperado: " << v2str(v)
               << ", obtido: " << v2str(res);
    }

}

TEST(TermTest, Normal) {
    for (int j=1; j < 5; j++) verifica(j);
}
