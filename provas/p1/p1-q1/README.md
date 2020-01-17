# Questão 1

Escreva um programa que ordena números usando pilha. Os números estão armazenados em um arquivo, cujo nome é informado no primeiro argumento de linha de comando. O ordenamento usando pilha pode ser feito com este algoritmo:


cria uma pilha p1
para cada número x
  cria uma pilha auxiliar p2
  enquanto número x for maior que topo da pilha p1
    desempilha um número y da pilha p1
    empilha esse número y na pilha p2
    se pilha p1 vazia então sai do laço
  empilha número x em p1
  enquanto p2 não for vazia
    desempilha um número y de p2
    empilha esse número y em p1


Ao final, a pilha p1 tem os números ordenados. Seu programa deve então apresentar esses números ordenados na tela (um por linha).
