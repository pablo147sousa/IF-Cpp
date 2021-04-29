// Implementação de grafo por Lista de Adjacências

#pragma once
#include <stdio.h>
#include <stdlib.h>

struct _linked_list_node
{
  int vertice;
  _linked_list_node *next;
};

struct Grafo
{
  unsigned n_vertices;
  _linked_list_node **arr_vertices;
};

//   Insere o new_node na lista de forma que os vértices de menor
// rótulo se concentrem no início da lista.
void _insere_ordenado(_linked_list_node *lista, _linked_list_node *new_node)
{
  if (lista != NULL && new_node != NULL)
  {
    _linked_list_node *node_atual = lista;

    /**
     *  Navega pela lista até o ultimo nó cujo o rótulo do vértice
     * seja menor que o rótulo do new_node.
     *  O loop também para se chegar no ultimo nó antes da condição.
    */
    while (node_atual->next != NULL && node_atual->next->vertice <= new_node->vertice)
    {
      node_atual = node_atual->next;
    }

    new_node->next = node_atual->next;
    node_atual->next = new_node;
  }
}

/**
 *    Verifica se o vértice v ocorre em g:
 *  - Em caso afirmativo: retorna o ponteiro para
 * a lista de adjacências de v;
 *  - Em caso negativo: retorna NULL;
*/
_linked_list_node *_busca_vert_no_grafo(Grafo *g, int v)
{
  for (int i = 0; i < g->n_vertices; i++)
  {
    if (g->arr_vertices[i]->vertice == v)
    {
      return g->arr_vertices[i];
    }
  }
  printf("O grafo nao possui o vertice {%d}\n", v);
  return NULL;
}

_linked_list_node *_cria_node(int vertice)
{
  _linked_list_node *node = (_linked_list_node *)malloc(sizeof(_linked_list_node));

  if (node == NULL)
  {
    printf("Nao foi possível alocar um novo node\n");
    return NULL;
  }

  node->next = NULL;
  node->vertice = vertice;
  return node;
}

Grafo *cria_grafo(unsigned n_vertices)
{
  // Alocando Grafo
  Grafo *g = (Grafo *)malloc(sizeof(Grafo));
  if (g == NULL)
  {
    printf("Nao deu para alocar o grafo\n");
    return NULL;
  }

  // Alocando vetor de nós
  _linked_list_node **node_arr = (_linked_list_node **)malloc(sizeof(_linked_list_node *) * n_vertices);
  if (node_arr == NULL)
  {
    free(g);
    printf("Nao deu para alocar o vetor de vertices\n");
    return NULL;
  }

  // Alocando nós e vertices
  _linked_list_node *n;
  for (int i = 0; i < n_vertices; i++)
  {
    n = _cria_node(i);
    if (n == NULL)
    {
      printf("Nao deu para alocar o vertice {%d}\n", i);
      for (int j = 0; j < i; j++)
      {
        free(node_arr[j]);
      }
      free(node_arr);
      free(g);
      return NULL;
    }

    node_arr[i] = n;
  }

  g->n_vertices = n_vertices;
  g->arr_vertices = node_arr;
  printf("Grafo sem arestas criado!\n");
  return g;
}

int vertices_sao_adjacentes(Grafo *g, int v_a, int v_b)
{
  if (v_a == v_b)
  {
    printf("vertices sao iguais\n");
    return 0;
  }

  _linked_list_node *aux_a = _busca_vert_no_grafo(g, v_a),
                    *aux_b = _busca_vert_no_grafo(g, v_b);
  if (aux_a == NULL || aux_b == NULL)
  {
    printf("Um ou mais vertices nao ocorrem no grafo\n");
    return 0;
  }

  int v_min = v_a < v_b ? v_a : v_b;
  _linked_list_node *aux_max = v_a < v_b ? aux_b : aux_a;

  while (aux_max != NULL && aux_max->vertice <= v_min)
  {
    if (aux_max->vertice == v_min)
    {
      return 1;
    }
    aux_max = aux_max->next;
  }
  return 0;
}

int cria_aresta(Grafo *g, int v_a, int v_b)
{
  if (v_a == v_b)
  {
    printf("Ainda nao e possivel criar um laço\n");
    return -1;
  }

  _linked_list_node *aux_a = _busca_vert_no_grafo(g, v_a),
                    *aux_b = _busca_vert_no_grafo(g, v_b),
                    *new_a, *new_b;
  if (aux_a == NULL || aux_b == NULL)
  {
    printf("valor de vertice invalido\n");
    return -1;
  }

  if (vertices_sao_adjacentes(g, v_a, v_b))
  {
    printf("Vertices ja sao adjacentes\n");
    return 0;
  }

  new_a = _cria_node(v_a);
  if (new_a == NULL)
  {
    printf("Nao foi possivel alocar no de vertice {%d}\n", v_a);
    return -1;
  }

  new_b = _cria_node(v_b);
  if (new_b == NULL)
  {
    free(new_a);
    printf("Nao foi possivel alocar no de vertice {%d}\n", v_b);
    return -1;
  }

  _insere_ordenado(aux_a, new_b);
  _insere_ordenado(aux_b, new_a);
  printf("Nova aresta criada\n");
  return 0;
}

void _mostra_lista_de_adjacencia(_linked_list_node *lista)
{
  _linked_list_node *atual = lista;
  printf("{");
  while (atual != NULL)
  {
    printf("%d", atual->vertice);
    if (atual->next != NULL)
    {
      printf(", ");
    }
    atual = atual->next;
  }
  printf("}\n");
}

void mostra_grafo(Grafo *g)
{
  if (g->n_vertices == 0)
  {
    printf("Grafo vazio\n");
  }

  printf("Grafo\nI\nv\n");
  for (unsigned i = 0; i < g->n_vertices; i++)
  {
    printf("[%d]->", g->arr_vertices[i]->vertice);
    _mostra_lista_de_adjacencia(g->arr_vertices[i]);
  }
}

// Retorna 1 caso consiga remover o nó;
// Retorna 0 caso contrário.
int _remove_node(_linked_list_node *lista, int v)
{
  if (lista == NULL)
  {
    printf("lista de adjacencia vazia\n");
    return 0;
  }

  _linked_list_node *ant = lista,
                    *aux = lista->next;

  // O laço termina com aux->vertice == v ou no ultimo nó.
  while (aux->next != NULL && aux->vertice < v)
  {
    ant = aux;
    aux = aux->next;
  }

  if (aux->vertice != v)
  {
    printf("Nao ha vertice {%d} na lista de adjacencia\n", v);
    return 0;
  }

  ant->next = aux->next;
  aux->next = NULL;
  free(aux);

  return 1;
}

int remove_aresta(Grafo *g, int v_a, int v_b)
{
  if (vertices_sao_adjacentes(g, v_a, v_b))
  {
    _linked_list_node *aux_a = _busca_vert_no_grafo(g, v_a),
                      *aux_b = _busca_vert_no_grafo(g, v_b);

    if (_remove_node(aux_a, v_b) && _remove_node(aux_b, v_b))
    {
      printf("Aresta removida\n");
      return 1;
    }
  }

  printf("vertices nao sao adjacentes\n");
  return 0;
}

int remove_vertice(Grafo *g, int v)
{
  _linked_list_node *lista_de_v = _busca_vert_no_grafo(g, v);
  if (lista_de_v == NULL)
  {
    printf("Vertice nao ocorre no grafo\n");
    return -1;
  }

  // Remove as arestas adjacêntes ao vertice v
  int v_aux;
  while (lista_de_v->next != NULL)
  {
    v_aux = lista_de_v->next->vertice;
    remove_aresta(g, v, v_aux);
  }

  // Dessa forma a ultima iteração atinge no máximo g->arr_vertices[n-1]
  g->n_vertices--;
  for (unsigned i = 0; i < g->n_vertices; i++)
  {
    // Reordena o array de vertices garantindo que, no final, o vertice v seja o último.
    if (g->arr_vertices[i] == lista_de_v)
    {
      g->arr_vertices[i] = g->arr_vertices[i + 1];
      g->arr_vertices[i + 1] = lista_de_v;
    }
  }
  g->arr_vertices = (_linked_list_node **)realloc(g->arr_vertices, sizeof(_linked_list_node *) * g->n_vertices);

  free(lista_de_v);
  printf("Vertice {%d} removido\n", v);

  return v;
}

void libera_grafo(Grafo *g)
{
  for (unsigned i = 0; i < g->n_vertices; i++)
  {
    while (g->arr_vertices[i] != NULL)
    {
      _remove_node(g->arr_vertices[i], g->arr_vertices[i]->vertice);
    }
    free(g->arr_vertices[i]);
  }
  free(g->arr_vertices);
  free(g);

  printf("Grafo liberado\n");
}
