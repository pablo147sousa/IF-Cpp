/** Exercício programa 1
 * Alunos:
 *  - Anilton Magalhães de Castro
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILENAME_LENGTH 20

/* Grafos - INÍCIO */
typedef struct grafo
{
  // implementa grafo
} Grafo;

/* Grafos - FIM */

/* Solução - INÍCIO */
typedef struct resposta
{
  unsigned length,
      *anterior,
      *custo;
} Resposta;

/* Solução - FIM */
/* Algoritmo de Dijkstra - INÍCIO */
Resposta *algoritmo_dijkstra(Grafo *g, unsigned s, unsigned t)
{
}
/* Algoritmo de Dijkstra - FIM */

int main(int argc, char const *argv[])
{
  //receba pela linha de comando o nome de um arquivo que contém a descrição de um digrafo.
  char filename[FILENAME_LENGTH];
  printf("Digite o nome do arquivo: ");
  scanf("%20s", filename);

  FILE *arq = fopen(filename, "r");
  if (arq == NULL)
  {
    printf("Arquivo nao foi aberto");
    return -1;
  }
  // Criar Grafo com os dados extraídos do arquivo

  // Criar Resposta utilizando o Algoritmo de Dijkstra

  // exibir um caminho de custo mínimo de s a t com base na Resposta.

  // Desalocar variáveis dinâmicas (Grafo, Resposta, etc...)

  return 0;
}
