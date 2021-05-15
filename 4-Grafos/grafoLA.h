// Implementação de grafo por Lista de Adjacências

#pragma once
#include <stdio.h>
#include <stdlib.h>

// Nó da lista de adjacência
typedef struct _node
{
  // Rótulo do vertice adjacente
  int v_adjacente;
  //Posição do vértice adjacente no array do grafo
  unsigned pos_adjacente;
  // Próximo nó ou NULL se este for o último
  _node *next;
} Lista;

struct Vertice
{
  // Rótulo do vértice
  int v;
  // posição do vértice no array do grafo
  unsigned _pos;
  // Valor temporário para alguns algoritmos
  unsigned _temp;
  // Lista de Adjacências do Vértice
  Lista *la;
};

struct Grafo
{
  unsigned n_vertices,
      m_arestas;
  Vertice **arr;
};

_node *_cria_node(int v_adjacente, unsigned pos_v)
{
  _node *node = (_node *)malloc(sizeof(_node));
  if (node == NULL)
  {
    printf("Nao foi possível alocar um novo node\n");
    return NULL;
  }

  node->next = NULL;
  node->v_adjacente = v_adjacente;
  node->pos_adjacente = pos_v;
  return node;
}

Vertice *_cria_vertice(int vertice, unsigned pos_v)
{
  Vertice *v = (Vertice *)malloc(sizeof(Vertice));
  if (v == NULL)
  {
    printf("Nao foi possível alocar um novo vertice\n");
    return NULL;
  }

  v->v = vertice;
  v->la = NULL;
  v->_temp = 0;
  v->_pos = pos_v;
  return v;
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

  // Alocando vetor de vértices
  Vertice **arr = (Vertice **)malloc(n_vertices * sizeof(Vertice *));
  if (arr == NULL)
  {
    free(g);
    printf("Nao deu para alocar o vetor de vértices\n");
    return NULL;
  }

  // Alocando vértices
  Vertice *v_aux;
  for (unsigned i = 0; i < n_vertices; i++)
  {
    v_aux = _cria_vertice(i, i);
    if (v_aux == NULL)
    {
      printf("Nao deu para alocar o vertice {%d}\n", i);
      for (unsigned j = 0; j < i; j++)
      {
        free(arr[j]);
      }
      free(arr);
      free(g);
      return NULL;
    }
    arr[i] = v_aux;
  }

  g->n_vertices = n_vertices;
  g->m_arestas = 0;
  g->arr = arr;
  printf("Grafo sem arestas criado!\n");
  return g;
}

// Retorna 1 se v_a possui um arco dirigido a v_b
// Retorna 0 caso contrário
bool _tem_arco(Vertice *v_a, int v_b)
{
  int v_atual = -1;
  _node *atual = v_a->la;
  while (atual != NULL && atual->v_adjacente <= v_b)
  {
    v_atual = atual->v_adjacente;
    atual = atual->next;
  }
  return v_atual == v_b;
}

bool _tem_aresta(Vertice *v_a, Vertice *v_b)
{
  return _tem_arco(v_a, v_b->v) && _tem_arco(v_b, v_a->v);
}

//   Insere o new_node na lista de forma que os vértices de menor
// rótulo se concentrem no início da lista.
void _insere_ordenado(Lista *lista, _node *new_node)
{
  /**
   *  Navega pela lista até o ultimo nó cujo o rótulo do vértice
   * seja menor que o rótulo do new_node.
   *  O loop também para se chegar no ultimo nó antes da condição.
  */
  _node *node_atual = lista;
  while (node_atual->next != NULL && node_atual->next->v_adjacente <= new_node->v_adjacente)
  {
    node_atual = node_atual->next;
  }

  new_node->next = node_atual->next;
  node_atual->next = new_node;
}

int _cria_arco(Vertice *v_a, Vertice *v_b)
{
  if (_tem_arco(v_a, v_b->v))
  {
    printf("Vertice %d ja tem arco para o vertice %d\n", v_a->v, v_b->v);
    return 0;
  }

  _node *n = _cria_node(v_b->v, v_b->_pos);
  if (n == NULL)
  {
    printf("Nao foi possivel alocar um novo no\n");
    return -1;
  }

  _insere_ordenado(v_a->la, n);
  return 0;
}

int cria_aresta(Vertice *v_a, Vertice *v_b)
{
  if (v_a == v_b)
  {
    printf("Ainda nao e possivel criar um laço\n");
    return -1;
  }

  if (_tem_aresta(v_a, v_b))
  {
    printf("Vertices ja sao adjacentes\n");
    return 0;
  }

  _cria_arco(v_a, v_b);
  _cria_arco(v_b, v_a);

  printf("Nova aresta criada\n");
  return 0;
}

void _mostra_lista_de_adjacencia(Lista *lista)
{
  _node *atual = lista;
  printf("{");
  while (atual != NULL)
  {
    printf("%d", atual->v_adjacente);
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
    printf("[%d]->", g->arr[i]->v);
    _mostra_lista_de_adjacencia(g->arr[i]->la);
  }
}

// Retorna 0 caso consiga remover o nó;
// Retorna 1 caso contrário.
int _remove_node(Lista *la, int v)
{
  if (la == NULL)
  {
    printf("lista de adjacencia vazia\n");
    return 0;
  }

  _node *ant = la,
        *aux = la->next;

  // O laço termina com aux->v_adjacente == v ou no ultimo nó.
  while (aux->next != NULL && aux->v_adjacente < v)
  {
    ant = aux;
    aux = aux->next;
  }

  if (aux->v_adjacente != v)
  {
    printf("Nao ha vertice {%d} na lista de adjacencia\n", v);
    return 1;
  }

  ant->next = aux->next;
  aux->next = NULL;
  free(aux);
  return 0;
}

int remove_aresta(Vertice *v_a, Vertice *v_b)
{
  if (_tem_aresta(v_a, v_b))
  {
    _remove_node(v_a->la, v_b->v);
    _remove_node(v_b->la, v_a->v);
    printf("Aresta removida\n");
    return 0;
  }

  printf("vertices nao sao adjacentes\n");
  return 1;
}

int remove_vertice(Grafo *g, unsigned pos_v)
{
  Vertice *v = g->arr[pos_v];
  while (v->la != NULL)
  {
    // Remove as arestas adjacêntes ao vertice v
    remove_aresta(v, g->arr[v->la->pos_adjacente]);
  }

  // Dessa forma a ultima iteração atinge no máximo g->arr_vertices[n-1]
  g->n_vertices--;
  for (unsigned i = pos_v; i < g->n_vertices; i++)
  {
    g->arr[i] = g->arr[i + 1];
  }
  g->arr[g->n_vertices] = NULL;
  g->arr = (Vertice **)realloc(g->arr, g->n_vertices * sizeof(Vertice *));

  int rot_v = v->v;
  free(v);

  printf("Vertice {%d} removido\n", rot_v);
  return rot_v;
}

void libera_grafo(Grafo *g)
{
  Lista *la;
  for (unsigned i = 0; i < g->n_vertices; i++)
  {
    la = g->arr[i]->la;
    while (la != NULL)
    {
      _remove_node(la, la->v_adjacente);
    }
    free(g->arr[i]);
  }

  free(g->arr);
  free(g);
  printf("Grafo liberado\n");
}
