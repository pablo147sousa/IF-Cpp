/** Exercício programa 1
 * Alunos:
 *  - Anilton Magalhães de Castro
 *  -
 *  -
 *  -
 * 
 * Convenções de Código: (sintam-se livres para melhores sugestões)
 *  - identação com 2 espaços
 *  - snake case para nomes de variaveis e funções
 *  -
 *  -
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILENAME_LENGTH 20

/* Grafos - INÍCIO */

typedef struct grafo
{
  int n_vertices;
  double **matriz_adjacente;
} Grafo;

Grafo *criar_grafo(int n_vertices)
{
  Grafo *g = (Grafo *)malloc(sizeof(Grafo));
  if (g == NULL)
  {
    return NULL;
  }

  double **matriz = (double **)malloc(n_vertices * sizeof(double *));
  if (matriz == NULL)
  {
    free(g);
    return NULL;
  }

  for (int i = 0; i < n_vertices; i++)
  {
    matriz[i] = (double *)malloc(n_vertices * sizeof(double));
    if (matriz[i] == NULL)
    {
      for (int j = 0; j < i; j++)
      {
        free(matriz[j]);
      }
      free(matriz);
      free(g);
      return NULL;
    }

    for (int k = 0; k < n_vertices; k++)
    {
      matriz[i][k] = -1;
    }
  }

  g->n_vertices = n_vertices;
  g->matriz_adjacente = matriz;

  return g;
}

void liberar_grafo(Grafo *g)
{
  for (int i = 0; i < g->n_vertices; i++)
  {
    free(g->matriz_adjacente[i]);
  }
  free(g->matriz_adjacente);
  free(g);
}

/* Grafos - FIM */
/* Solução - INÍCIO */

typedef struct resposta
{
  int length,
      *anterior;
  double *custo;
} Resposta;

Resposta *alocar_resposta(int len)
{
  Resposta *r = (Resposta *)malloc(sizeof(Resposta));
  if (r == NULL)
  {
    return NULL;
  }

  r->length = len;
  r->anterior = (int *)calloc(len, sizeof(int));
  if (r->anterior == NULL)
  {
    free(r);
    return NULL;
  }

  r->custo = (double *)calloc(len, sizeof(double));
  if (r->custo == NULL)
  {
    free(r->anterior);
    free(r);
    return NULL;
  }

  return r;
}

void mostrar_caminho_recursivo(Resposta *r, int vertice)
{
  if (r->anterior[vertice - 1] != -1)
  {
    mostrar_caminho_recursivo(r, r->anterior[vertice - 1]);
    printf(" (%d -> %d)", r->anterior[vertice - 1], vertice);
  }
}

void mostrar_caminho_minimo(Resposta *r, int start, int stop)
{
  if (r->custo[stop - 1] == INFINITY)
  {
    printf("Nao ha caminho do vertice %d para o vertice %d:\n", start, stop);
    printf("O custo para chegar no vertice %d entao e: %lf\n", stop, INFINITY);
  }
  else
  {
    printf("Caminho minimo do vertice %d para o vertice %d:\n", start, stop);
    mostrar_caminho_recursivo(r, stop);
    printf("\nO custo para chegar no vertice %d entao e: %lf\n", stop, r->custo[stop - 1]);
  }
}

void liberar_resposta(Resposta *r)
{
  free(r->custo);
  free(r->anterior);
  free(r);
}

/* Solução - FIM */
/* Algoritmo de Dijkstra - INÍCIO */

Resposta *algoritmo_dijkstra(Grafo *g, int start, int stop)
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
  int n, m, s, t;
  fscanf(arq, "%d %d %d %d", &n, &m, &s, &t);

  Grafo *g = criar_grafo(n);
  if (g == NULL)
  {
    printf("Grafo nao foi criado\n");
    fclose(arq);
    return -1;
  }

  int u, v;
  double c;
  for (int i = 0; i < m; i++)
  {
    fscanf(arq, "%d %d %lf", &u, &v, &c);
    g->matriz_adjacente[u - 1][v - 1] = c;
  }

  // Mostrando matriz de adjacência - REMOVER DO ARQUIVO FINAL
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%6.lf ", g->matriz_adjacente[i][j]);
    }
    printf("\n");
  }

  // Criar Resposta utilizando o Algoritmo de Dijkstra
  Resposta *r = algoritmo_dijkstra(g, s, t);
  if (r == NULL)
  {
    printf("Nao ha resposta\n");
    liberar_grafo(g);
    fclose(arq);
    return -1;
  }

  // exibir um caminho de custo mínimo de s a t com base na Resposta.
  mostrar_caminho_minimo(r, s, t);

  /** REMOVER DO ARQUIVO FINAL
   * int ant[5] = {-1, 1, 2, 5, 2};
   * double cost[5] = {0, 5, 9, 13, 7};
   * Resposta r = {5, ant, cost};
   * mostrar_caminho_minimo(&r, 1, 4);
  */

  // Desalocar variáveis dinâmicas (Grafo, Resposta, etc...)
  liberar_grafo(g);
  fclose(arq);

  return 0;
}
