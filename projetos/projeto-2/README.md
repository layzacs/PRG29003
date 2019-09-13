# Projeto 1 - Kevin Bacon

> Conteúdo retirado do moodle do IFSC SJ, disciplina de Programação II do professor Marcelo Maia Sobral.

O objetivo do projeto 1 é: escrever um programa que calcule a distância de Bacon de um dado ator.

Este projeto foi feito usando o CLion.

## Introdução

A distância de Bacon é dada pelo menor número de ligações entre um dado ator e o ator Kevin Bacon. As ligações dizem respeito a filmes em que os atores atuaram. Por exemplo, se um ator esteve em um mesmo filme que Kevin Bacon, sua distância de Bacon é 1. Se ele atuou em um filme com um outro ator, e esse outro ator trabalhou com Kevin Bacon, então sua distância é 2. O Oracle de Bacon é um sítio web que faz o cálculo dessa distância para cada ator conhecido. Ali há também a história de como e porque essa distância foi inventada...

O cálculo da distância de Bacon de um ator qualquer implica navegar por um mapa que relaciona os atores e filmes conhecidos. O ponto de partida da busca deve ser Kevin Bacon.

### O mapa de atores e filmes

O conjunto de atores e filmes conhecidos está armazenado em um arquivo de texto. No entanto, para facilitar o desenvolvimento do projeto, é fornecida uma pequena biblioteca de programação capaz de ler esse arquivo e acessar seus dados. Basicamente, essa biblioteca disponibiliza a classe Mapa mostrada a seguir:

```
class Mapa {
  public:
    // construtor: cria um objeto Mapa que acessa o conteúdo do arquivo cujo nome é
    // informado no parâmetro path
    Mapa(const string & path);

    // Obtem a lista de filmes em que um ator trabalhou
    fila<string> obtem_filmes(const string & ator);

    // Obtem a lista de atores que atuaram em um filme
    fila<string> obtem_atores(const string & filme);
};
```

Um exemplo de uso dessa classe Mapa pode ser visto neste pequeno trecho de código:

```
Mapa dados("data.txt");
fila<string> filmes = dados.obtem_filmes("Kevin Bacon");

while (! filmes.vazia()) {
  string umFilme = filmes.desenfileira();
  cout << "Filme: " << umFilme << endl;
}
```

### Algoritmos de busca

A busca por um ator, tendo como ponto de partida Kevin Bacon, pode ser feita de duas formas:

- **Usando um algoritmo de busca em largura**:
verificam-se atores em ordem de distância em relação a Kevin Bacon. A distância é definida pela quantidade de filmes que devem ser seguidos para se chegar a um ator específico. Quer dizer primeiro verificam-se todos os atores que atuaram junto com Kevin Bacon em algum filme. Se o ator procurado não foi encontrado nessa primeira busca, então, para cada ator que trabalhou com Kevin Bacon, verificam-se os atores que atuaram com ele em algum outro filme. Se ainda assim o ator procurado não foi encontrado, então repete-se o procedimento para todos os atores identificados na segunda busca, e assim por diante (ver figura a seguir). Esse tipo de algoritmo precisa de uma fila para ser implementado.


- **Usando um algoritmo de busca em profundidade**: verificam-se os atores partindo-se de Kevin Bacon e seguindo-se cada ator que com ele trabalhou em algum filme, seguindo-se a cada vez uma sequência de atores até o ator mais distante (ver figura a seguir). Esse tipo de algoritmo precisa de uma pilha para ser implementado.

### Algoritmos de busca

O algoritmo de busca em largura pode ser implementado usando uma fila, onde se armazenam os próximos atores a visitar.

```
algoritmo busca_bfs():
  cria uma fila
  enfileira nó inicial
  enquanto fila não vazia
    desenfileira um nó
    se for o nó procurado então retorna o valor do nó
    para cada nó adjacente ao nó desenfileirado
      enfileira o nó adjacente
```
O algoritmo de busca em profundidade, por sua vez, pode ser implementado usando uma pilha, onde se armazenam os próximos links a visitar. Ele fica muito parecido com a busca em largura, como se pode perceber neste pseudo-código:
```
algoritmo busca_dfs():
  cria uma pilha
  empilha o nó inicial
  enquanto pilha não vazia
    desempilha um nó
    se for o nó procurado, então retorna o valor do nó
    para cada nó adjacente ao nó desempilhado
      empilha nó adjacente
```
### Produto a entregar

Seu programa deve ser capaz de fazer a busca de um determinado ator usando esses dois algoritmos. Cabe ao usuário selecionar qual algoritmo de busca usar quando for executar o programa. Quando o ator procurado for informado, devem ser apresentadas estas informações:

- Distância de Bacon
- Sequência filmes e atores intermediários entre Kevin Bacon e o ator procurado

Este trabalho pode ser feito por equipes de até dois alunos (excepcionalmente três alunos). A entrega deve conter os nomes dos alunos da equipe.
