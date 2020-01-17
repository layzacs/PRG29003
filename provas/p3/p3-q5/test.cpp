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
#include "gtest/gtest.h"

using namespace std;
using namespace prglib;

//Implementar a operação contem, que retorna verdadeiro se uma arvore
//        estiver contida em outra:

// retorna:
// false: se outra árvore não estiver contida nesta árvore
// true: se outra árvore estiver perfeitamente contida nesta árvore, de forma
// que existe uma subárvore com mesma topologia que a outra árvore

//bool contem(arvore<T> * outra);


class TesteQuestao: public ::testing::Test {
protected:

    virtual void SetUp() {
        srand(clock());
    }

    double rand1() {
        double r = rand() % 1024;

        if (r == 0) return r;
        return (r+1)/1024;
    }

    double drand(double menor, double maior) {
        return menor + (maior-menor)*rand1();
    }

    vector<double> gera_lista(int n, double mx, double mn) {
        vector<double> v;
        while (n-- > 0) {
            v.push_back(drand(mn, mx));
        }
        return v;
    }

    arvore<double> * gera_arvore(vector<double> & v, vector<double> & v2) {
        auto a = new arvore<double>(v[0]);
        for (auto &x: v) {
            a->adiciona(x);
        }
        for (auto &x: v2) {
            a->adiciona(x);
        }
        return a;
    }

    string vreport(vector<double> & v, const string & nome) {
        ostringstream out;
        out <<nome + ": ";
        for (auto & x: v) out << x << ",";
        return out.str();
    }
    string lreport(lista<double> & l, const string & nome) {
        ostringstream out;
        out <<nome + ": ";
        l.escrevaSe(out, ",");
        return out.str();
    }

};

TEST_F(TesteQuestao, Normal)
{
    int N = 10;

    while (N-- > 0) {
        int m = 3 + (rand() % 8);
        double maior=8, menor=4;
        arvore<double> * a, * a2;

        auto v = gera_lista(m, maior, menor);

        double maior2, menor2;
        if ((rand() % 100) > 50) {
            menor2 = maior+1;
            maior2 = menor2 + 4;
        } else {
            maior2 = menor - 1;
            menor2 = maior2 - 4;
        }

        auto v2 = gera_lista(m, maior2, menor2);

        try {
            vector<double> v3;

            a = gera_arvore(v, v2);
            a2 = gera_arvore(v2, v3);
        } catch(...) {
            FAIL() << "Erro ao criar uma árvore (verifique construtor ou adiciona)";
        }

        try {
            if (! a->contem(a2)) {
                for (auto & x: v2) v.push_back(x);
                FAIL()<< vreport(v2, "Árvore: ")
                << vreport(v, " está contida em ");
            }
        } catch (...) {
            FAIL()<<"Exceção inesperada ao chamar contem !";
        }
    }
}

TEST_F(TesteQuestao, Ausente)
{
    int N = 10;

    while (N-- > 0) {
        int m = 3 + (rand() % 8);
        double maior=8, menor=4;
        arvore<double> * a, * a2;

        auto v = gera_lista(m, maior, menor);

        double maior2, menor2;
        if ((rand() % 100) > 50) {
            menor2 = maior+1;
            maior2 = menor2 + 4;
        } else {
            maior2 = menor - 1;
            menor2 = maior2 - 4;
        }

        auto v2 = gera_lista(m, maior2, menor2);

        try {
            vector<double> v3;

            a = gera_arvore(v, v3);
            a2 = gera_arvore(v2, v3);
        } catch(...) {
            FAIL() << "Erro ao criar uma árvore (verifique construtor ou adiciona)";
        }

        try {
            if (a->contem(a2)) {
                FAIL()<< vreport(v2, "Árvore: ")
                      << vreport(v, " NÃO está contida em ");
            }
        } catch (...) {
            FAIL()<<"Exceção inesperada ao chamar contem !";
        }
    }
}

TEST_F(TesteQuestao,Misturada)
{
    int N = 10;

    while (N-- > 0) {
        int m = 3 + (rand() % 8);
        double maior=8, menor=4;
        arvore<double> * a, * a2;

        auto v = gera_lista(m, maior, menor);

        auto v2 = gera_lista(m, maior, menor);

        try {
            vector<double> v3;

            a = gera_arvore(v, v2);
            a2 = gera_arvore(v2, v3);
        } catch(...) {
            FAIL() << "Erro ao criar uma árvore (verifique construtor ou adiciona)";
        }

        try {
            if (a->contem(a2)) {
                lista<double> l;
                a->listePreOrder(l);

                FAIL()<< vreport(v2, "Árvore: ")
                      << lreport(l, " NÃO está contida EXATAMENTE em ");
            }
        } catch (...) {
            FAIL()<<"Exceção inesperada ao chamar contem !";
        }
    }
}

TEST_F(TesteQuestao,Identidade)
{
    int N = 10;

    while (N-- > 0) {
        int m = 3 + (rand() % 8);
        double maior=8, menor=4;
        arvore<double> * a, * a2;

        auto v = gera_lista(m, maior, menor);

        try {
            vector<double> v3;

            a = gera_arvore(v, v3);
            a2 = gera_arvore(v, v3);
        } catch(...) {
            FAIL() << "Erro ao criar uma árvore (verifique construtor ou adiciona)";
        }

        try {
            if (! a->contem(a2)) {
                FAIL()<< vreport(v, "Árvore: ")
                      << vreport(v, " está contida EXATAMENTE em ")
                      << " pois são idênticas";
            }
        } catch (...) {
            FAIL()<<"Exceção inesperada ao chamar contem !";
        }
    }
}
