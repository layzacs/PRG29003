# Questão 2

Implementa a operação sublista da estrutura de dados lista, a qual deve ser declarada assim:


void sublista(lista<T> & sub, int pos1, int num)
Essa operação copia para a lista sub os num dados a partir da posição pos1.


OBS:

se num < 0: copiar os num dados  que antecedem pos1
se num exceder os limites da lista: copiar só até o limite
