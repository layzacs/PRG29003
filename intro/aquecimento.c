// 1. Escreva um programa que leia uma sequência de números pelo teclado, e informe ao final qual o maior e o menor números lidos
// 2. Modifique o programa para que sejam apresentados todos os números maiores ou iguais à média dos números lidos



int main(void) {
  int qtd=0, j=0, maior, menor, vet[100], soma=0, media;

  printf("Quantos números serão inseridos:\n");
  scanf("%d", &qtd);

// compara maior e menor, adiciona o valor à soma para posteriormente calcular a média.
  for (j=0;j<qtd;j++) {

    printf("Insira o próximo número:\n");
    scanf("%d", &vet[j]);

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
