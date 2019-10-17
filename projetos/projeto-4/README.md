Fazer uma struct para salvar os verbetes

struct verbete {
  string palavra
  string classe_gramatical
  lista<string> significado
}

função:
// o arquivo é aberto e passado como parâmetro

ifstream arq("verbete.txt");


// a função ifstream já começa a partir do ponto em que o arquivo deixou de ser lido, então ela funcionaria para todo o arquivo
verbete cria_verbete(ifstream &arq) {
  string verbete novo;
  ...

  (se não conseguir nenhum verbete gera exceção);
  return novo;
}

while (true) {
  try {
  verbete verb  = cria_verbete(arq);
  } catch (...) {
    break;
  }

## Função cria_verbete

A função cria_verbete deve criar um verbete por vez.
Processo de criação:

Abre o arquivo do ponto em que foi interrompido:
Primeira linha sempre vai ser a palavra.
A segunda linha sempre vai ser a classe gramatical.
Da terceira linha em diante podemos ter um ou mais significados (até chega em uma linha em que '(' seja o primeiro caractere)
