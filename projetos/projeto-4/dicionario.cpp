#include "dicionario.h"

// Procura todos os verbetes que iniciam com dado prefixo
lista<Verbete> procura_prefixo(arvore<Verbete> * arv, string & prefixo) {
    lista<Verbete> verbetes;
    // Pegamos o tamanho do prefixo passado para comparar o prefixo com os primeiros x caracteres
    int size = prefixo.size();
    // Inicia a iteração da árvore
    arv->inicia();
    while (!arv->fim()) {
        Verbete verb = arv->proximo();
        // quando a substring gerada for igual ao prefixo passado, anexa o verbete na lista de verbetes.
        string aux = verb.palavra.substr(0, size);
        if (aux == prefixo) {
            verbetes.insere(verb);
        }
    }
    return verbetes;
}

bool adiciona_verbete(arvore<Verbete> * arv, Verbete & verb) {

    // Primeiro testamos se o verbete a ser adicionado já existe na árvore.
    try {
        arv->obtem(verb);
        cout << "A palavra já existe no dicionário." << endl;
        return false;
    } catch (...) {
        if (!verb.palavra.empty() && !verb.classe.empty()) {
            arv->adiciona(verb);

        } else {
            cout << "Você digitou um verbete inválido." << endl;
            return false;
        }
        // caso o verbete não exista ainda, adiciona o verbete à árvore.
    }

    // salva a árvore atual no arquivo dict.txt
    salva_arvore_arquivo(arv);
    return true;
}

// Procura todos os verbetes que são passados na lista de palavras.
lista<Verbete> procura_todos_verbetes(arvore<Verbete> * arv, lista<string> & palavras) {
    palavras.inicia();
    lista<Verbete> verbetes;

    // inicia a iteração da lista de palavras
    while (!palavras.fim()) {

        // Usamos a função procura_verbete aqui.
        Verbete verb = procura_verbete(arv, palavras.proximo());

        // Testamos aqui se o verbete foi encontrado ou não pelo valor da classe.
        if (verb.classe != "none") {
            verbetes.insere(verb);
        }
    }

    return verbetes;
}

// Procura por um verbete na arvore
Verbete procura_verbete(arvore<Verbete> * arv, string & palavra) {

    // É dado um valor para aux.classe apenas para poder distinguir caso a função retorne o verbete auxiliar (quando não é encontrado o verbete na arvore).
    Verbete aux;
    aux.palavra = palavra;
    aux.classe = "none";

    // Testa se o verbete existe na arvore. Caso exista, retorna o verbete.
    try {
        Verbete verb = arv->obtem(aux);
        return verb;
    } catch (...) {
        cout << "A Palavra " << palavra << " não foi encontrada." << endl;
        cout << endl;
        // No moodle dizia para criar uma exceção, mas prefiri deixá-la de fora para manter o flow do programa.
        // Caso a palavra não seja encontrada, apenas vola para o menu.
        //throw -1;
        return aux;
    }
}

// Cria árvore a partir da lista de verbetes.
arvore<Verbete> * prepara_dicionario() {
    // A função abaixo cria a arvore a partir da lista de verbetes.
    auto arv = cria_arvore_lista();
    lista<Verbete> verbetes;

    // As vezes (acredito que por causa da prglib?) a árvore não adiciona todos os verbetes, por causa da raiz inicial.
    // Quando a árvore carrega todos os verbetes, ela fica com aproximadamente 124000 verbetes. Por isso, o while abaixo
    // checa se a árvore foi criada corretamente. Caso não tenha sido, ela chama a função de novo para tentar novamente.
    // Lembrando que só acontece caso o arquivo pronto do dicionário não exista.
    while (arv->tamanho() < 120000) {
        cout << "Erro ao criar a arvore. Adotando um novo valor para raiz e tentando de novo." << endl;
        arv = cria_arvore_lista();
    }

    // Salva árvore no arquivo dict.txt
    if (salva_arvore_arquivo(arv)) {
        cout << "Dicionário foi carregado." << endl;
    } else {
        cout << "Não foi possível criar arquivo para salvar dicionário. Cheque permissionamento e espaço disponível e tente novamente." << endl;
    }
    return arv;
}

// Salva dados da árvore no arquivo dict.txt
bool salva_arvore_arquivo(arvore<Verbete> * arv) {
    lista<Verbete> verbetes;
    // Criamos uma lista em pré ordem (para manter a estrutura da árvore)
    arv->listePreOrder(verbetes);
    string path = "../data/dict.txt";
    ofstream arq(path);

    if (!arq.is_open()) {
        return false;
    }
    // Inicia iteração dos verbetes
    verbetes.inicia();

    // Enquanto houver próximo, salva os verbetes dentro do arquivo.
    while (!verbetes.fim()) {
        Verbete verb = verbetes.proximo();
        arq << verb.palavra << endl;
        arq << verb.classe << endl;
        lista<string> significados = verb.significados;
        significados.inicia();
        while (!significados.fim()) {
            arq << significados.proximo() << endl;
        }
        arq << endl;
    }
    return true;
}

// cria uma arvore com os dados da lista passada
arvore<Verbete> * cria_arvore_lista() {

    ifstream dict("../data/dict.txt");

    // Se o arquivo não abrir, quer dizer q não existe o arquivo dicionario. Iremos criar a arvore de acordo com o arquivo verbetes.txt.
    if (!dict.is_open()) {

        cout << "Arquivo dict.txt n existe, criando a partir de verbetes" << endl;
        string path = "../data/verbetes.txt";

        // Criamos a lista de verbetes, a partir do arquivo verbetex.txt
        lista<Verbete> verbetes = cria_lista_verbetes(path);


        // embaralha para pegar uma raiz aleatória para a árvore, para ela não ficar muito comprida
        verbetes.embaralha();

        verbetes.inicia();

        // cria a árvore com uma raiz aleatória
        auto arv = new arvore<Verbete>(verbetes.proximo());

        // adiciona todos os verbetes á arvore.
        while (!verbetes.fim()) {
            arv->adiciona(verbetes.proximo());
        }

        /*
        cout << "Tamanho da arvore: " << arv->tamanho() << endl;
        cout << "Altura da arvore: " << arv->altura() << endl;
        */

        // A árvore é balanceada o máximo possível
        arv->balanceia(true);

        return arv;

        // caso o arquivo dict.txt exista, os verbetes são resgatados dele.
    } else {

        string path = "../data/dict.txt";
        lista<Verbete> verbetes = cria_lista_verbetes(path);
        // a lista de verbetes agora não precisa ser embaralhada porque ela está na ordem da árvore balanceada.
        // inicia a iteração da lista de verbetes e cria a árvore.
        verbetes.inicia();
        auto * arv = new arvore<Verbete>(verbetes.proximo());

        while (!verbetes.fim()) {
            arv->adiciona(verbetes.proximo());
        }
        return arv;

    }

}

// Cria lista com verbetes de um arquivo
lista<Verbete> cria_lista_verbetes(string & path) {
    lista<Verbete> verbetes;
    ifstream arq(path);

    if(!arq.is_open()){
        cout << "Arquivo Invalido" << endl;
        throw -1;
    }

    lista<string> aux;
    lista<string> significados;
    Verbete verb;
    string line;

    // pega cada linha do arquivo
    while(getline(arq, line)) {

        // quando a linha estiver vazia, sabemos que um verbete chegou a fim.
        if (line.empty()) {
            // Aqui fazemos este teste para ver se o verbete capturado possui nome, classe e significado(s)
            if (aux.comprimento() >= 3) {
                aux.inicia();


                // pegamos os dados resgatados e inserimos eles no verbete verb.
                verb.palavra = aux.proximo();
                verb.classe = aux.proximo();
                while (!aux.fim()) {
                    significados.anexa(aux.proximo());
                }
                verb.significados = significados;

                // Limpa a formatação do dado palavra
                if (verb.palavra[0] == '*' && verb.palavra[1] == ' ') {
                    verb.palavra = verb.palavra.substr(2, (verb.palavra.find_last_of('*') - 1));
                }
                if (verb.palavra[0] == '*') {
                    verb.palavra = verb.palavra.substr(1, (verb.palavra.find_last_of('*') - 1));
                }

                // adiciona o verbete criado na lista de verbetes.
                verbetes.anexa(verb);
                // esvazia a lista auxiliar e a lista de significados para empregar o próximo verbete.
                aux.esvazia();
                significados.esvazia();
            }

            // Se o comprimento da lista aux for igua a 2, temos um verbete constituido apenas por nome e classe gramatical.
            if (aux.comprimento() == 2) {
                aux.inicia();
                verb.palavra = aux.proximo();
                verb.classe = aux.proximo();

                // Aqui, estamos adicionando uma lista vazia ao verbete, pois ele não possui significados.
                verb.significados = significados;

                if (verb.palavra[0] == '*' && verb.palavra[1] == ' ') {
                    verb.palavra = verb.palavra.substr(2, (verb.palavra.find_last_of('*') - 1));
                }
                if (verb.palavra[0] == '*') {
                    verb.palavra = verb.palavra.substr(1, (verb.palavra.find_last_of('*') - 1));
                }

                // adiciona o verbete criado na lista de verbetes.
                verbetes.anexa(verb);
                aux.esvazia();
            }
        }
        // condição do if abaixo serve para excluir as linhas que iniciam com ')'.
        else if (line[0] != '(') {
            aux.anexa(line);
        }
    }

    // retorna uma lista de verbetes.
    return verbetes;
}
