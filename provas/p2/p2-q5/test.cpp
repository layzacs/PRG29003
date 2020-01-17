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
    arvore<int> * gentree(int n=0) {
        if (n == 0) n = 64 + (rand() % 64);
        auto a = new arvore<int>(rand() % 1024);
        while (n-- > 0) a->adiciona(rand() % 1024);
        return a;
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

    arvore<int> * copia(arvore<int> * raiz) {
        lista<int> l;
        raiz->listePreOrder(l);
        return new arvore<int>(l);
    }

    bool compara(arvore<int> * a1, arvore<int> * a2) {
        lista<int> l1, l2;

        a1->listePreOrder(l1);
        a2->listePreOrder(l2);

        return l1 == l2;
    }

    bool compara2(arvore<int> * a1, arvore<int> * a2) {
        lista<int> l1, l2;

        a1->listeInOrder(l1);
        a2->listeInOrder(l2);

        return l1 == l2;
    }

};

TEST_F(TesteQuestao, Balanceada)
{
    for (int j=0; j < 10; j++) {
        auto raiz = gentree(64);
        raiz = raiz->balanceia();
        auto outra = copia(raiz);

        try {
            auto nova = balanceia_condicional(outra);

            if (!compara(raiz,nova)) {
                int h = raiz->altura();
                int n = raiz->tamanho();
                FAIL() << "Árvore não precisa ser balanceada, pois sua altura é " << h << " e possui " << n << " dados";
            }
        } catch (...) {
            FAIL() << "testa_se_existe disparou uma excecao ... ";
            return;
        }
    }
}

TEST_F(TesteQuestao, BalanceadaMaisOuMenos)
{
    for (int j=0; j < 10; j++) {
        auto raiz = gentree(64);
        raiz = raiz->balanceia();
        int hok = -1 + ceil(log2(raiz->tamanho()));
        int maior = raiz->obtemMaior()+1;
        int plus = 2*hok-1;
        while (raiz->altura() < plus) raiz->adiciona(maior++);
        auto outra = copia(raiz);

        try {
            auto nova = balanceia_condicional(outra);

            if (!compara(raiz, nova)) {
                int h = raiz->altura();
                int n = raiz->tamanho();
                FAIL() << "Árvore ainda não precisa ser balanceada, pois sua altura é " << h << " e possui " << n << " dados";
            }
        } catch (...) {
            FAIL() << "testa_se_existe disparou uma excecao ... ";
            return;
        }
    }
}

TEST_F(TesteQuestao, Desbalanceada)
{
    for (int j=0; j < 10; j++) {
        auto raiz = gentree(64);
        int hok = -1 + ceil(log2(raiz->tamanho()));
        int maior = raiz->obtemMaior()+1;
        int plus = 3*hok;
        while (raiz->altura() < plus) raiz->adiciona(maior++);
        auto outra = copia(raiz);

        try {
            auto nova = balanceia_condicional(outra);
            int hok = -1 + ceil(log2(nova->tamanho()));

            if (! compara2(raiz, nova)) {
                FAIL() << "Conteúdo da árvore mudou após balanceia_condicional: tinha "
                       << raiz->tamanho() << " dados, e agora tem " << nova->tamanho();
            }
            if (nova->altura() >= 2*hok) {
                int h = raiz->altura();
                int n = raiz->tamanho();
                FAIL() << "Árvore precisa ser balanceada, pois sua altura é " << h << " e possui " << n << " dados";
            }
        } catch (...) {
            FAIL() << "testa_se_existe disparou uma excecao ... ";
            return;
        }
    }
}
