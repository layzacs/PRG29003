//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include <prglib.h>
#include <map>
#include "questao.h"
#include "gtest/gtest.h"

using namespace std;
using prglib::lista;
using prglib::arvore;

const string Palavras = "../data/portugues.txt";

class TesteQuestao: public ::testing::Test {
protected:
    arvore<string> * raiz;
    lista<string> tudo;

    virtual void SetUp() {
        srand(clock());
        ifstream arq(Palavras);
        raiz = new arvore<string>(arq);
        raiz->listeInOrder(tudo);
    }

    string prefixo(int n=2) {
        tudo.embaralha();
        tudo.inicia();
        while (! tudo.fim()) {
            auto & w = tudo.proximo();
            if (w.size() > n) return w.substr(0, n);
        }
        throw -1;
    }

    lista<string> palavras(const string & pref) {
        lista<string> l;

        tudo.inicia();
        while (! tudo.fim()) {
            auto & w = tudo.proximo();
            //if (w < pref) break;
            if (w.compare(0, pref.size(), pref) == 0) l.anexa(w);
        }

        return l;
    }

    string randstr() {
        int n = 5 + (rand() % 5);
        string r;

        while (n-- > 0) {
            char c = 65 + (rand() % 26);
            r += c;
        }
        return r;
    }

    string junta(lista<string> & l, char delim=',', int lim=0) {
        string r;

        if (l.vazia()) return r;
        l.inicia();
        r = l.proximo();
        lim--;
        while (! l.fim() and lim > 0) r += delim + l.proximo();

        return r;
    }

    string v2str(vector<string> & v) {
        string r;

        for (auto & s: v) r += s + ':';
        if (! r.empty()) r.pop_back();

        return r;
    }

    vector<string> split(const string & s, const string & delim) {
        vector<string> v;
        if (s.empty()) return v;

        int pos = 0;
        while (pos != string::npos) {
            int pos1 = s.find_first_not_of(delim, pos);
            if (pos1 == string::npos) break;
            pos = s.find_first_of(delim, pos1);
            if (pos == string::npos) {
                v.push_back(s.substr(pos1));
//            strip(v.back());
                break;
            } else {
                v.push_back(s.substr(pos1, pos-pos1));
//            strip(v.back());
            }
        }
        return v;
    }


};

TEST_F(TesteQuestao, Simples)
{
    lista<string> res;
    string pref = prefixo(1);
    auto l = palavras(pref);

    try {
        res = busca_por_prefixo(raiz, pref);
    } catch (...) {
        FAIL() << "busca_por_prefixo disparou uma excecao ... ";
        return;
    }

    l.ordena();
    res.ordena();
    if (! (l == res)) {
        FAIL() << "Esperado: " << junta(l, ',') << "; OBTIDO: " << junta(res, ',');
        return;
    }
}

TEST_F(TesteQuestao, Normal)
{
    for (int n=2; n < 6; n++) {
        lista<string> res;
        string pref = prefixo(n);
        auto l = palavras(pref);

        try {
            res = busca_por_prefixo(raiz, pref);
        } catch (...) {
            FAIL() << "busca_por_prefixo disparou uma excecao ... ";
            return;
        }

        l.ordena();
        res.ordena();
        if (!(l == res)) {
            FAIL() << "Prefixo: " << pref << "; Esperado: " << junta(l, ',', 10) << "; OBTIDO: " << junta(res, ',', 10)
                   << " (mostrando 10 primeiras palavras somente)";
            return;
        }
    }
}
