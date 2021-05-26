#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "./conexo.h"

int main(int argc, char const *argv[])
{
  unsigned n_vertices, m_arestas, u, v;
  printf("Informe o numero de vertices: ");
  scanf("%u", &n_vertices);
  printf("Informe o numero de arestas: ");
  scanf("%u", &m_arestas);

  Grafo *g = cria_grafo(n_vertices);
  if (g == NULL)
  {
    printf("Nao foi possivel criar Grafo\n");
    return 1;
  }

  for (unsigned i = 0; i < m_arestas; i++)
  {
    printf("Informe o vertice u: ");
    scanf("%u", &u);
    printf("Informe o vertice v: ");
    scanf("%u", &v);

    u--;
    v--;

    cria_aresta(g->arr[u], g->arr[v]);
    printf("Aresta criada entre os vertices {%d} e {%d}\n", g->arr[u]->v, g->arr[v]->v);
  }

  mostra_grafo(g);
  if (e_conexo(g))
    printf("Grafo e conexo!\n");
  else
    printf("Grafo nao e conexo!\n");

  // libera_grafo(g);

  return 0;
}
