#include <stdio.h>

int main(void) {
  int qtd=0, j=0, maior, menor, vet[100], soma=0, media, ret=0, i=0;
  char buffer[100+1];
  // declarando a variavel database do tipo FILE
  FILE *database;

  // teste de abertura do arquivo, se não conseguir retorna mensagem de erro. O arquivo é aberto somente para leitura.
  if ((database = fopen("database.dat", "r")) == NULL) {
     printf("Erro na abertura de arquivo\n");
  }
  // EOF = "end of file".
  while  (fscanf (database, "%d", &vet[i]) != EOF) {
    i++;
  }
  
  fclose(database);
  printf("vet[3]=%d\n", vet[3]);
  qtd = i;
// compara maior e menor, adiciona o valor à soma para posteriormente calcular a média.
  for (j=0;j<qtd;j++) {

    soma = soma + vet[j];

    if (j==0) {
      maior=vet[j];
      menor=vet[j];
    }
    else {
      if (vet[j] > maior) {
        maior = vet[j];
      }
  
      if (vet[j] < menor) {
        menor = vet[j];
      }
    }
  }
  media = soma/qtd;

  printf("O maior número é %d, o menor número é %d\n", maior, menor);
  printf("A média dos valores é %d\n", media);
  
// mostra números iguais ou maiores que a média.
  for (j=0; j<qtd; j++) {
    if (vet[j] >= media) {
      printf("O número %d é maior ou igual a média.\n", vet[j]);
    }
  }
}
