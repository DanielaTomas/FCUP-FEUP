# Projeto

## Q1

Escreva um programa phrases que dado um ficheiro de texto na linha de comando imprima o numero de frases no texto e as escreva de seguida, uma por linha no terminal.
Utilize o mais possível as funcões da "Standard C Library" para manipulação de "strings" e ficheiros ("buffered I/O"). 
Note que as frases podem terminar com um ponto final mas também com pontos de exclamação ou de interrogação.

## Q2

Escreva um programa addmx que para duas matrizes de números inteiros positivos n × m fornecidas na linha de comando calcule uma matriz que n × m que é a sua soma.
O programa deverá lançar m processos filho. Cada processo Pi, com 0 ≤ i ≤ m − 1, é responsável por calcular a coluna i da matriz resultado. 
As matrizes dadas como input e a matriz resultado devem ser colocadas num segmento de memória partilhado pelos processos para que todos tenham acesso às ditas (sugestão: veja como usar a função mmap da clib). 
A matriz resultado é assim calculada "em paralelo" pelos vários processos filho. 
O processo pai deve esperar pelo fim de todos os processos filho após o que escreve para o “stdout” a matriz resultado com o mesmo formato do ficheiro original.

## Q3

Escreva um programa cypher que crie duas "pipes" entre um processo (pai) e um seu processo filho. 
Uma das "pipes" permite enviar informação do processo pai para o processo filho. 
A outra permite enviar informação no sentido contrário. O processo pai recebe uma ou mais strings do "stdin" e envia-a para o processo filho através de uma das "pipes".
O processo filho recebe-a e substitui todas as palavras de acordo com a informação no ficheiro cypher.txt.
Depois de processada envia-a de volta, através da outra “pipe”, para o processo pai, que a escreve no “stdout”. 
Nota: quando aplicado duas vezes o programa deve produzir o texto original, pois a composição de duas substituições deriva cada palavra original.
