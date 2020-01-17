#include "proc.h"

bool operator<(const ator & s1, const ator & s2) {
    return s1.n_filmes > s2.n_filmes;
}

bool operator>(const ator & s1, const ator & s2) {
    return s1.n_filmes > s2.n_filmes;
}


lista<string> separa(const string & texto, const string & sep) {

    int found = 0;
    lista<string> l;
    string inicial = texto;

    // Enquanto o delimitador dado for encontrado na string, é criada uma substring da posição anterior até o delimitador.
    while (found != -1 && (! inicial.empty())) {
        found = inicial.find(sep);
        string aux = inicial.substr(0, found);
        if (!aux.empty()) {
            l.anexa(aux);
        }

        inicial = inicial.substr (found + sep.size());

    }
    return l;
}

lista<filmes> obtem_dados(const string & path) {

    ifstream arq(path);

    if (! arq.is_open()) {
        cout << "Arquivo Inválido." << endl;
    }

    string x;
    lista<filmes> todos_atores;

    // Inicialmente separa-se o nome do filme e o ano em que ele foi feito;
    while (getline(arq, x)) {
        int found = x.find_first_of(';');
        string a_filme = x.substr(0, found);
        int found2 = x.find_last_of(';');

        string b_filme = x.substr(found+1, 4);
        string aux = x.substr(found2+1);
        // É criada uma lista de atores, usando a função separa para delimitar os nomes e posteriormente anexá-los a lista.
        lista<string> c_filme = separa(aux, ",");
        // O nome do filme, o ano e a lista de atores são inseridos na struct e depois anexados a lista v.
        struct filmes a = {a_filme, b_filme, c_filme};
        todos_atores.anexa(a);

    }
    return todos_atores;
}

lista<string> obtem_atores(const string & filme, lista<filmes> todos_filmes) {
    // Para obter os atores de um dado filme, basta percorrer a lista de structs, encontrar o nome do filme na struct e resgatar a lista de atores inserida com ele.
    struct filmes x;
    todos_filmes.inicia();
    while(!todos_filmes.fim()) {
        x = todos_filmes.proximo();
        // Abaixo é feito o teste para ver se x.filme é igual ao filme passado para a função.
        if (x.filme == filme) {
            return x.atores;
        }
    }
    return x.atores;
}


// Na função obtem filmes, para cada filme na struct todos_filmes, é procurado em sua lista de atores o ator passado para a função.
// Caso o ator seja encontrado, salva o nome do filme na lista de filmes do ator.
lista<string> obtem_filmes(const string & ator, lista<filmes> todos_filmes) {

    lista<string> filmes_ator;
    struct filmes x;
    todos_filmes.inicia();
    // Começa a percorrer a lista de filmes
    while(!todos_filmes.fim()) {
        x = todos_filmes.proximo();
        x.atores.inicia();
        // Começa a percorrer a lista de atores de um filme
        while (!x.atores.fim()) {
            if (x.atores.proximo() == ator) {
                filmes_ator.anexa(x.filme);
            }
        }

    }

    return filmes_ator;
}

// Na função obtem_colegas, o nome de todos os atores que trabalharam com um ator dado é inserido em uma lista.
// Para tal, é percorrido a lista de filmes. Quando o ator dado é encontrado na lista de atores de um filme,
// todos os atores da lista atores são inseridos em uma nova lista de colegas (testando anteriormente o colega já está listado).
lista<string> obtem_colegas(const string & ator, lista<filmes> todos_filmes) {
    lista<string> colegas;
    lista<string> filmes_ator;

    struct filmes x;

    todos_filmes.inicia();

    // Inicia a percorrer a lista que contém todos os filmes. Percorre todos os atores de cada um dos filmes.
    // Se dentro da lista de atores estiver o ator dado, adiciona os outros a lista colegas.
    while(!todos_filmes.fim()) {
        x = todos_filmes.proximo();
        lista<string> aux = x.atores;
        x.atores.inicia();
        while (!x.atores.fim()) {
            if (x.atores.proximo() == ator) {
                aux.inicia();

                while (!aux.fim()) {
                    string colega = aux.proximo();

                    //procura o colega na lista para não inserir dados repetidos.
                    try {
                        colegas.procura(colega);
                    } catch (...) {
                        colegas.anexa(colega);
                    }

                }
            }
        }

    }
    colegas.retira(ator);
    return colegas;
}

// Função ordena os colegas de acordo com a quantidade de filmes que fizeram com o ator dado.
// Basicamente é criada uma lista onde os atores de cada um dos filmes do ator dado são anexados.
// A lista é ordenada (alfabeticamente). A quantidade de vezes que o nome repete na lista é igual a quantidade de vezes que o nome repetido fez um filme com o ator.
// É criada uma struct que salva o nome do ator e a quantidade de vezes em que ele aparece na lista.
int ordena_colegas(const string & ator, lista<filmes> todos_filmes, int limite) {
    lista<string> filmes_ator = obtem_filmes(ator, todos_filmes);
    if (filmes_ator.vazia()) {
        return 0;
    }
    lista<string> todos_colegas;
    lista<struct ator> todos_colegas_cont;
    struct ator s_colega;

    filmes_ator.inicia();

    while(!filmes_ator.fim()) {
        string aux = filmes_ator.proximo();
        lista<string> colegas = obtem_atores(aux, todos_filmes);
        colegas.inicia();
        while (!colegas.fim()) {
            todos_colegas.anexa(colegas.proximo());
        }
    }
    // Nomes da lista são ordenados alfabeticamente.
    todos_colegas.ordena();
    todos_colegas.inicia();

    string colega_atual = todos_colegas.proximo();
    int cont=1;
    // Inicia a percorrer a lista com todos os colegas
    while (!todos_colegas.fim()) {

        string aux = todos_colegas.proximo();

        // Quando o próximo da lista for igual ao anterior, incrementa o contador. Se não, ele é adicionado a struct com contador = 1.
        if (colega_atual == aux) {
            cont++;
        } else {
            struct ator a;
            a.nome = colega_atual;
            a.n_filmes = cont;
            todos_colegas_cont.anexa(a);
            colega_atual = aux;
            cont = 1;
        }
    }

    int total=0;
    // A lista é ordenada de acordo com o valor do dado cont da struct. Para isso, foi estabelecido o significado do operador "<" acima no código (linha 3).
    todos_colegas_cont.ordena();
    todos_colegas_cont.inicia();

    // Inicia iteração para imprimir os dados salvos na tela. É inserido um limite para caso o usuário queira apenas os primeiros x atores.
    while(!todos_colegas_cont.fim()) {

        if (total == limite) {
            break;
        }

        struct ator & aux = todos_colegas_cont.proximo();
        if (aux.nome != ator) {
            cout << aux.nome << ":" << aux.n_filmes << endl;
            total++;
        }

    }
    return 1;
}


// A função ordena todos os atores de acordo com a quantidade de filmes feitos por cada um.
// Basicamente, é criada uma lista todos_atores que contém todos os atores de todos os filmes.
// Os atores são ordenados em ordem alfabetica, para que possam ser contados.
// Após, é feito o mesmo processo da função acima, contando quantas recorrencias do ator existem dentro da lista.
void ordena_atores(lista<filmes> todos_filmes, int limite) {
    todos_filmes.inicia();
    lista<string> todos_atores;
    lista<struct ator> todos_atores_cont;
    // cria lista com todos os atores (repetindo seus nomes)
    while (!todos_filmes.fim()) {
        struct filmes aux = todos_filmes.proximo();
        aux.atores.inicia();
        while (!aux.atores.fim()) {
            todos_atores.anexa(aux.atores.proximo());
        }
    }

    // ordena todos os atores por ordem alfabetica, (quantidade de linhas iguais é a quantidade de filmes que o ator que se repete fez)
    todos_atores.ordena();

    // É iniciada a iteração para inserção dos dados na struct. A struct salva o nome do ator e a quantidade de filmes feito por ele.
    todos_atores.inicia();
    string ator_atual = todos_atores.proximo();
    int cont=1;
    while (!todos_atores.fim()) {

        string aux = todos_atores.proximo();

        // Se o anterior da lista for igual ao atual, incrementa o contador. Caso contrário, ele é adicionado a nova lista com o contador = 1.
        if (ator_atual == aux) {
            cont++;
        } else {
            struct ator a;
            a.nome = ator_atual;
            a.n_filmes = cont;
            todos_atores_cont.anexa(a);
            ator_atual = aux;
            cont = 1;
        }
    }
    // ordena a lista de struct ator, de acordo com o tamanho da variável cont
    todos_atores_cont.ordena();
    todos_atores_cont.inicia();

    int total=0;

    // É iniciada a iteração para imprimir na tela os dados, com limite dado pelo usuário.
    while(!todos_atores_cont.fim()) {

        if (total == limite) {
            break;
        }

        struct ator & aux = todos_atores_cont.proximo();

        cout << aux.nome << ":" << aux.n_filmes << endl;
        total++;
    }

}

