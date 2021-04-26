// Implementação de pilha

#include <stdio.h>
#include <stdlib.h>

struct _node
{
  int rotulo;
  struct _node *abaixo;
};

struct Pilha
{
  unsigned _max, tam = 0;
  struct _node *topo;
};

int esta_vazia(struct Pilha *p)
{
  return p->tam == 0;
}

int esta_cheia(struct Pilha *p)
{
  return p->tam == p->_max;
}

struct Pilha *cria_pilha(unsigned limite)
{
  // Cria a pilha com limite definido.

  struct Pilha *p = (struct Pilha *)malloc(sizeof(struct Pilha));

  if (p == NULL)
  {
    printf("não foi possível criar pilha");
    return NULL;
  }

  p->_max = limite;
  p->tam = 0;
  p->topo = NULL;

  return p;
}

int empilha(struct Pilha *p, int rot)
{
  /**
   * Cria um nó com o rótulo @param rot e o adiciona na pilha @param p.
   * Retorna 0 se tudo for bem sucedido, caso contrário, retorna -1.
  */
  if (esta_cheia(p))
  {
    printf("Stack Overflow!!!");
    return -1;
  }

  struct _node *novo = (struct _node *)malloc(sizeof(struct _node));
  if (novo == NULL)
  {
    printf("sem memoria para alocar elemento da pilha!!");
    return -1;
  }

  novo->rotulo = rot;
  novo->abaixo = p->topo;
  p->topo = novo;
  p->tam++;

  return 0;
}

int desempilha(struct Pilha *p)
{
  /**
   * Remove o nó no topo da pilha e retorna o elemento que estava lá.
   * Retorna 0 em caso de Stack Underflow.
  */

  if (esta_vazia(p))
  {
    printf("Stack Underflow!!");
    return 0;
  }

  struct _node *antigo = p->topo;
  int rot = antigo->rotulo;

  p->topo = antigo->abaixo;
  p->tam--;

  free(antigo);

  return rot;
}

int libera_pilha(struct Pilha *p)
{
  while (!esta_vazia(p))
  {
    desempilha(p);
  }
  
  free(p);

  return 0;
}
