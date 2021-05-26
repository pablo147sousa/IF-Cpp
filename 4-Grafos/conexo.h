// Implementação de algoritmos sobre conexidade

#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "./grafoLA.h"
#include "./pilhaLL.h"

/** 
 * - se faltar memória para computar a resposta, devolve -1;
 * - se o grafo não for conexo, devolve 0;
 * - se o grafo for conexo, devolve 1;
*/
int e_conexo(Grafo *g)
{
  // grafo vazio é conexo por vacuidade
  if (g->n_vertices == 0)
  {
    return 1;
  }

  int num_vert_visitados = 1,
      posicao_de_v = 0;
      
  Vertice *v = g->arr[posicao_de_v];
  _node *aresta;
  Pilha *p = cria_pilha(g->n_vertices);
  if (p == NULL)
  {
    return -1;
  }

  int  *vert_visitados = (int *)calloc(g->n_vertices, sizeof(int));
  if (vert_visitados == NULL)
  {
    libera_pilha(p);
    printf("impossível alocar vetor\n");
    return -1;
  }

  vert_visitados[posicao_de_v] = 1;
  empilha(p, v->_pos);

  while (!esta_vazia(p))
  {
    posicao_de_v = desempilha(p);
    aresta = g->arr[posicao_de_v]->la;

    // Para cada vértice w adjacente a v
    while (aresta != NULL)
    {
      if (vert_visitados[aresta->pos_adjacente] == 0)
      {
        vert_visitados[aresta->pos_adjacente] = 1;
        empilha(p, aresta->pos_adjacente);
        num_vert_visitados++;
      }
      aresta = aresta->next;
    }
  }
  
  return num_vert_visitados == g->n_vertices;
}
