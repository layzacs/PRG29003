#include "proc.h"

bool operator<(const ator & s1, const ator & s2) {
    return s1.num > s2.num;
}

// Separa uma string dado um delimitador
lista<string> separa(const string & texto, const string & sep) {

    int found = 0;
    lista<string> l;
    string inicial = texto;

    // Enquanto o delimitador dado for encontrado na string, é criada uma substring da posição anterior até o delimitador.
    while (found != -1 && (! inicial.empty())) {
        found = inicial.find(sep);
        string aux = inicial.substr(0, found);
        // Algumas exceções foram adicionadas abaixo para economizar memória. Eram casos de alta recorrência no arquivo que não eram de fato nomes de atores.
        if (!aux.empty() && (aux != " Jr.") && (aux != " the") && (aux != " Sr.")) {
            l.anexa(aux);
        }

        inicial = inicial.substr (found + sep.size());

    }
    return l;
}

// Obtem os dados do arquivo, inserindo-os em uma tabela hash com as chaves sendo os filmes e valores sendo uma lista dos atores do filme.
thash<lista<string>> obtem_dados(const string & path) {

    ifstream arq(path);
    if (! arq.is_open()) {
        cout << "Arquivo Inválido." << endl;
    }
    string x;
    // número primo!
    thash<lista<string>> todos_filmes(300007);

    // Inicialmente separa-se o nome do filme e o ano em que ele foi feito;
    while (getline(arq, x)) {

        // nome do filme é salvo na string filme
        int found = x.find_first_of(';');
        string filme = x.substr(0, found);
        // é excluido tudo na string x até o último char ';' (tratamento para que a função separa funcione corretamente)
        int last = x.find_last_of(';');
        x.erase(0, last+1);
        // É criada uma lista de atores, usando a função separa para delimitar os nomes e posteriormente anexá-los a lista.
        lista<string> atores = separa(x, ",");
        // O nome do filme é uma chave e a lista de atores é o valor desta chave.
        // O if abaixo é adicionado apenas para "limpar" os filmes sem atores do arquivo.
        if (!atores.vazia()) {
            todos_filmes.adiciona(filme, atores);
        }
    }
    return todos_filmes;
}

// Na função obtem filmes, para cada filme na tabela todos_filmes, é procurado em sua lista de atores o ator passado para a função.
// Caso o ator seja encontrado, salva o nome do filme na lista de filmes do ator.
lista<string> obtem_filmes(const string & ator, thash<lista<string>> & todos_filmes) {

    lista<string> filmes_ator;
    string filme;

    // é criada uma lista contendo todas as chaves da tabela hash; as chaves são os filmes.
    auto filmes = todos_filmes.chaves();
    filmes->inicia();
    // Começa a percorrer a lista de filmes
    while(!filmes->fim()) {
        filme = filmes->proximo();
        lista<string> atores = todos_filmes[filme];

        atores.inicia();
        // Começa a percorrer a lista de atores de um filme. Quando o ator da vez for igual ao ator passado, o filme é adicionado a lista de filmes.
        while (!atores.fim()) {
            if (atores.proximo() == ator) {
                filmes_ator.anexa(filme);
            }
        }
    }
    return filmes_ator;
}

// Obtém todos os atores que trabalharam em um filme com um dado ator.
// Basicamente, os filmes do ator dado são obtidos. O nome de cada um dos atores de todos os filmes é inserido em uma tabela hash.
// A tabela hash sobrescreve chaves repetidas.
// OBS: a lista retornada é um shared_prt, ou seja, é um ponteiro pra uma lista (criado pela biblioteca de tabela hash)
shared_ptr<lista<string>> obtem_colegas(const string & ator, thash<lista<string>> & todos_filmes) {
    lista<string> filmes_ator;

    // Número primo!
    thash<int> colegas(5239);


    // Primeiro pegamos os filmes em que o ator participou.
    filmes_ator = obtem_filmes(ator, todos_filmes);

    // Agora que temos uma lista com os atores, e cada filme da lista é uma chave para a nossa tabela hash de dados,
    // vamos percorrer os filmes, pegando seus atores e adicionando a uma nova tabela hash.
    filmes_ator.inicia();

    while(!filmes_ator.fim()) {
        string filme = filmes_ator.proximo();
        // Pegamos a lista de atores do filme
        lista<string> atores = todos_filmes[filme];

        atores.inicia();
        while (!atores.fim()) {
            // Os atores repetidos são automaticamente sobrescritos, então no final teremos uma tabela sem repetições.
            colegas.adiciona(atores.proximo(), 0);
        }
    }
    auto chaves = colegas.chaves();
    chaves->retira(ator);
    chaves->ordena();
    return chaves;
}

// Ordena atores de acordo com a quantidade de colegas.
// Basicamente, é criada uma tabela com todos os atores (como as chaves) e todos os filmes de cada um dos atores como seus valores.
// Para cada um dos atores, é retornado todos os seus colegas. A quantidade de colegas é salva em uma struct.
void ordena_atores_colegas(thash<lista<string>> & todos_filmes, int limite) {
    // thash que irá guardar todos os atores (como chaves) com sua lista de filmes como valores.
    thash<lista<string>> todos_atores(2000007);

    // Lista de structs, que será retornada no final, contendo o nome do ator e o numero de colegas.
    lista<ator> s_atores;

    // Cria a lista de filmes e inicia a iteração
    auto filmes = todos_filmes.chaves();
    filmes->inicia();

    // cria tabela com todos os atores, adicionando os seus filmes como uma lista de valores
    while(!filmes->fim()) {
        string filme = filmes->proximo();
        lista<string> atores = todos_filmes[filme];
        atores.inicia();

        while(!atores.fim()) {
            string ator = atores.proximo();

            if (todos_atores.existe(ator)) {
                todos_atores[ator].anexa(filme);
            } else {
                lista<string> aux;
                aux.anexa(filme);
                todos_atores.adiciona(ator, aux);
            }
        }
    }

    // Vamos criar um lista com as chaves e começar a iteração com o objetivo de limpar os dados antes de iniciar o processo de contagem dos colegas
    auto atores = todos_atores.chaves();
    atores->inicia();
    while (!atores->fim()) {
        string ator = atores->proximo();
        // Limpamos um pouco a tabela final para aumentar a velocidade do algoritmo: Qualquer ator com menos de 18 filmes não entra no top 10000 atores mais populares.
        if (todos_atores[ator].comprimento() < 18) {
            todos_atores.remove(ator);
        }
    }

    // Inicia a interação da tabela com todos os atores
    atores = todos_atores.chaves();
    atores->inicia();
    while (!atores->fim()) {
        // Tabela hash onde serão salvos todos os colegas de um ator (usamos tabela hash pois ela não aceita dois valores iguais de chave)
        thash<int> todos_colegas(204207);
        struct ator b;

        string ator = atores->proximo();
        // Pega lista de filmes de um ator e inicia iteração
        lista<string> filmes_ator = todos_atores[ator];
        filmes_ator.inicia();

        while(!filmes_ator.fim()) {

            // pega todos os atores que trabalharam em um filme junto com um ator e os adiciona a lista de todos os colegas.
            lista<string> colegas = todos_filmes[filmes_ator.proximo()];
            colegas.inicia();
            while (!colegas.fim()) {
            todos_colegas.adiciona(colegas.proximo(), 0);
            }
        }
        // Finalmente, adiciona o ator e seu número de colegas na estrutura, que é salva em uma lista de estruturas.
        b.nome = ator;
        b.num = todos_colegas.tamanho();
        s_atores.anexa(b);
    }

    // ordena a lista de atores de acordo com o número de colegas e inicia iteração
    s_atores.ordena();

    // Inicio da iteração da lista final, composta pelas estruturas que possuem o numero total de colegas de cada ator
    s_atores.inicia();
    int cont = 0;
    while(!s_atores.fim() && cont < limite) {
        struct ator aux = s_atores.proximo();
        cout << aux.nome << ": " << aux.num << endl;
        cont++;
    }

}

// A função ordena todos os atores de acordo com a quantidade de filmes feitos por cada um.
// Basicamente, a tabela de todos os filmes é percorrida. É criada uma tabela com todos os atores.
// Quando um ator aparece em um filme pela segunda vez, um contador é incrementado.
// No final, temos uma lista de estruturas contendo o nome do ator e a quantidade de vezes em que ele aparece em um filme.
void ordena_atores(thash<lista<string>> todos_filmes, int limite) {
    thash<int> todos_atores(2000007);
    lista<ator> l_atores;
    auto filmes = todos_filmes.chaves();

    // Inicia iteração da tabela de todos os filmes
    filmes->inicia();

    // Todos os atores de cada um dos filmes são adicionados a uma nova tabela que conterá todos os atores.
    while(!filmes->fim()) {
        string filme = filmes->proximo();
        lista<string> atores = todos_filmes[filme];
        atores.inicia();
        while(!atores.fim()) {
            string ator = atores.proximo();
            // Se o ator ainda não está na tabela, ele é adicionado com valor 1.
            // Caso o ator já se encontre na tabela, significa que já foi varrido um filme (ou vários) do qual ele já fez parte. Incrementamos o contador.
            if (!todos_atores.existe(ator)) {
                todos_atores.adiciona(ator, 1);
            } else {
                todos_atores[ator]++;
            }
        }

    }

    auto atores = todos_atores.chaves();
    // Iniciamos a iteração da tabela de todos os atores.
    atores->inicia();

    while (!atores->fim()) {
        struct ator b;
        string ator = atores->proximo();

        // O nome e quantidade de filmes do ator são inseridos em uma lista feita de estruturas.
        b.nome = ator;
        b.num = todos_atores[ator];
        l_atores.anexa(b);
    }

    // Ordena a lista de acordo com o valor salvo nas structs, inicia iteração e imprime na tela os valores contidos na lista de estruturas.
    l_atores.ordena();
    l_atores.inicia();
    int cont = 0;
    while(!l_atores.fim() && cont < limite) {
        struct ator aux = l_atores.proximo();
        cout << aux.nome << ": " << aux.num << endl;
        cont++;
    }

}

// Obtém os atores que trabalharam em todos os filmes passados na lista filmes, por meio de uma tabela hash.
// Basicamente, um contador é incrementado para cada vez que o ator aparece nas listas de atores. O contador é salvo como valor na tabela.
// Se o valor do contador é igual a quantidade de filmes passados, o ator trabalhou em todos eles.
lista<string> obtem_atores_filmes(lista<string> filmes, thash<lista<string>> & todos_filmes) {
    thash<int> atores(7207);
    int tam = filmes.comprimento();
    lista<string> atores_final;

    // Inicia a iteração da tabela contendo todos os filmes
    filmes.inicia();
    while (!filmes.fim()) {
        string filme = filmes.proximo();
        if (todos_filmes.existe(filme)) {
            // Pegamos os atores de um determinado filme e começamos a iteração.
            lista<string> l_atores = todos_filmes[filme];
            l_atores.inicia();
            while (!l_atores.fim()) {
                string ator = l_atores.proximo();
                // Se o ator existe na tabela de todos os atores, incrementamos seu valor (quantidade de filmes em que aparece). Caso contrário, ele é adicionado a tabela.
                if (atores.existe(ator)) {
                    atores[ator]++;
                } else {
                    atores.adiciona(ator, 1);
                }
            }
        }
        // Caso o filme passado seja inválido, ele é apenas descartado. Isso faz com que a quantidade de filmes a ser comparada no final diminua em 1.
        else {
            cout << "O filme " << filme << " não foi encontrado. Ele será excluido da pesquisa." << endl;
            tam--;
        }
    }
    if (tam == 0) {
        cout << "Não foi passado nenhum filme válido." << endl;
        return atores_final;
    }
    // Inicia a iteração da tabela de atores. Se o valor atrelado ao ator for igual a quantidade de filmes passados, ele é anexado a lista final.
    auto chaves = atores.chaves();
    chaves->inicia();
    while (!chaves->fim()) {
        string aux = chaves->proximo();
        if (atores[aux] == tam) {
            atores_final.anexa(aux);
        }
    }
    return atores_final;
}

