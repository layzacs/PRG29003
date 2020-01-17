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

const string Arq = "../data/arq1.txt";
const string Pares = "../data/par";

class TesteQuestao: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
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

    string junta(lista<string> & l, char delim=',') {
        string r;

        if (l.vazia()) return r;
        l.inicia();
        r = l.proximo();
        while (! l.fim()) r += delim + l.proximo();

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

    lista<string> obtem_atore(const string & path, string & ator) {
        ifstream arq(path);
        map<string,lista<string>> res;
        lista<string> l;
        string w;

        while (getline(arq, w)) {
            auto v = split(w, ";");
            res[v[1]].anexa(v[0]);
            l.anexa(v[1]);
        }
        l.embaralha();
        ator = l[0];
        return res[ator];
    }

    lista<string> obtem2atores(string & a1, string & a2, int n=1) {
        ifstream arqa(Pares+to_string(n));
        string w;
        lista<string> la;

        while (getline(arqa, w)) {
            la.anexa(w);
        }
        la.embaralha();
        auto va = split(la[0], ":");
        a1 = va[0];
        a2 = va[1];

        ifstream arq(Arq);
        map<string,lista<string>> res;
        lista<string> lf;

        while (getline(arq, w)) {
            auto v = split(w, ";");
            res[v[1]].anexa(v[0]);
        }

        auto & l1 = res[a1];
        l1.inicia();
        while (! l1.fim()) {
            auto & f = l1.proximo();
            try {
                res[a2].procura(f);
                lf.anexa(f);
            } catch(...) {}
        }
        return lf;
    }
};

TEST_F(TesteQuestao, Vazia)
{
    lista<string> l, res;

    try {
        res = filmes_em_comum(Arq, "dona bilica", "seu maneca");
    } catch (...) {
        FAIL() << "filmes_em_comum disparou uma excecao ... ";
        return;
    }

    if (res.comprimento() > 0) {
        FAIL() << "filmes_em_comum retornou alguns filmes, mas atores com certeza são desconhecidos !";
        return;
    }
}

TEST_F(TesteQuestao, Atores)
{
    for (int j=2; j < 6; j++) {
        string ator1, ator2;

        auto lf = obtem2atores(ator1, ator2, j);
        lf.ordena();
        lista<string> res;

        try {
            res = filmes_em_comum(Arq, ator1, ator2);
            res.ordena();
            if (!(res == lf)) {
                FAIL() << "Esperado: " << junta(lf) << "; Obtido: " << junta(res);
            }
        } catch (...) {
            FAIL() << "filmes_em_comum disparou uma excecao ... ";
        }
    }
}

