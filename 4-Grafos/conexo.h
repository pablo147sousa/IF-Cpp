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

  Pilha *p = cria_pilha(g->n_vertices);
  if (p == NULL)
  {
    return -1;
  }

  _linked_list_node *aux;
  int num_vert_visitados = 1,
      posicao_de_v = 0,
      v = g->arr_vertices[posicao_de_v]->vertice;

  int  *vert_visitados = (int *)calloc(g->n_vertices, sizeof(int));
  if (vert_visitados == NULL)
  {
    libera_pilha(p);
    printf("impossível alocar vetor\n");
    return -1;
  }

  vert_visitados[posicao_de_v] = 1;
  empilha(p, v);

  while (!esta_vazia(p))
  {
    v = desempilha(p);
    aux = _busca_vert_no_grafo(g, v);

    // Para cada vértice w adjacente a v
    while (aux != NULL)
    {
      if (vert_visitados[posicao_de_v] == 0)
      {
        vert_visitados[aux->vertice] = 1;
        empilha(p, aux->vertice);
        num_vert_visitados++;
      }
      aux = aux->next;
      posicao_de_v = _posicao_de_v_no_grafo(g, v);
    }
  }
  
  return num_vert_visitados == g->n_vertices;
}
