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

class TesteQuestao: public ::testing::Test {
protected:

    virtual void SetUp() {
        srand(clock());
    }

    arvore<int> * gentree(int n=0) {
        if (n == 0) n = 64 + (rand() % 64);
        auto a = new arvore<int>(rand() % 1024);
        while (n-- > 0) a->adiciona(rand() % 1024);
        a = a->balanceia(true);
        return a;
    }

    arvore<int> * gensubtree(arvore<int> * raiz) {
        arvore<int> * a = raiz;
        int h = 1 + (rand() % (raiz->altura()/2));
        while (h-- > 0) {
            if (a->altura() < 3) break;
            int dir = (rand() % 2);
            if (dir) a = a->esquerda();
            else a = a->direita();
        }
        return copia(a);
    }

    arvore<int> * copia(arvore<int> * raiz) {
        lista<int> l;
        raiz->listePreOrder(l);
        return new arvore<int>(l);
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

    int sorteia(arvore<int> * raiz) {
        int menor = raiz->obtemMenor();
        int maior = raiz->obtemMaior();

        return menor + (rand() % (maior-menor));
    }

};

TEST_F(TesteQuestao, Existe)
{
    for (int j=0; j < 10; j++) {
        auto raiz = gentree(16);
        int dado = sorteia(raiz);

        try {
            auto ok = testa_se_existe(raiz, dado);

            if (! ok) {
                lista<int> l;
                raiz->listePreOrder(l);
                ostringstream out;

                out << "PRE-ORDER DA árvore=";
                l.escrevaSe(out, ",");
                FAIL() << "dado " << dado << " talvez exista dentro da árvore, mas sua função retornou " << ok
                       << ": " << out.str();
            }
        } catch (...) {
            FAIL() << "testa_se_existe disparou uma excecao ... ";
            return;
        }
    }
}

TEST_F(TesteQuestao, NaoExiste)
{
    for (int j=0; j < 10; j++) {
        auto raiz = gentree(16);
        int dado;

        if (rand() % 2) dado = raiz->obtemMaior() + (1 + (rand() % 16));
        else dado = raiz->obtemMenor() - (1 + (rand() % 16));

        try {
            auto ok = testa_se_existe(raiz, dado);

            if (ok) {
                lista<int> l;
                raiz->listePreOrder(l);
                ostringstream out;

                out << "PRE-ORDER DA árvore=";
                l.escrevaSe(out, ",");
                FAIL() << "dado " << dado << " não existe dentro da árvore, mas sua função retornou " << ok
                       << ": " << out.str();
            }
        } catch (...) {
            FAIL() << "testa_se_existe disparou uma excecao ... ";
            return;
        }
    }
}
