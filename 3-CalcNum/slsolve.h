// Implementação de algoritmos de resolução de sistemas lineares

#pragma once
#include <math.h>
#include "./matriz.h"

#define _MAX_ITER 100
#define _MAX_REPEAT 5
#define _ERRO_TOLERAVEL 1e-5

/**
 *    Algoritmo de substituição retroativa.
 * 
 * @param m matriz aumentada de coeficientes;
 * @param n número de linhas da matriz;
 * @param x vetor de n posições para armazenar o resultado;
 * 
 * @return o tipo de resposta:
 *  -1 se o SL não for TS;
 *  0 se o SL TS for determinado;
 *  1 se o SL TS for indeterminado;
 *  2 se o SL TS for incompatível;
*/
int sub_retro(double **m, unsigned n, double *x)
{
  int i, j, tipo = 0;
  double soma;

  for (i = n - 1; i >= 0; i--)
  {
    soma = 0;
    // Não ocorre na primeira iteração
    for (j = i + 1; j < n; j++)
    {
      soma += m[i][j] * x[j];
    }

    if (m[i][i] == 0)
    {
      if (m[i][n] - soma < _ERRO_TOLERAVEL)
      {
        // x[i] é variavel livre
        x[i] = 0;
        // SL indeterminado
        tipo = 1;
      }
      else
      {
        // SL incompatível
        tipo = 2;
        return tipo;
      }
    }
    else
    {
      x[i] = (m[i][n] - soma) / m[i][i];
    }
  }
  return tipo;
}

/**
 *    Transforma a matriz aumentada em um SL TS equivalente
 * @param m a matriz aumentada a ser modificada pelo método;
 * @param n o número de linhas da matriz.
*/
void metodo_gauss(double **m, unsigned n)
{
  int i, j, k;
  double *aux, mult;

  for (i = 0; i < n - 1; i++)
  {
    // Se o pivô da linha for 0
    if (m[i][i] == 0)
    {
      j = i + 1;

      // busca a próxima linha sem pivô nulo
      while (j < n && m[j][i] == 0)
      {
        j++;
      }

      // Se houver linha j com pivô não nulo
      // Troca as linhas i e j.
      if (j < n)
      {
        aux = m[i];
        m[i] = m[j];
        m[j] = aux;
      }
    }

    // Realiza a pivotação
    if (m[i][i] != 0)
    {
      for (j = i + 1; j < n; j++)
      {
        mult = -m[j][i] / m[i][i];
        m[j][i] = 0;

        for (k = i + 1; k <= n; k++)
        {
          m[j][k] += mult * m[i][k];
        }
      }
    }
  }
}

unsigned *metodo_jordan(double **m, unsigned n)
{
  int i, j, k, l;
  double mult;
  bool houve_troca_de_coluna = false;

  unsigned coluna_aux,
      *aux = (unsigned *)calloc(n, sizeof(unsigned));
  if (aux == NULL)
  {
    printf("Vetor auxiliar não alocado\n");
    return NULL;
  }

  for (i = 0; i < n; i++)
  {
    aux[i] = i;
  }

  for (i = 0; i < n; i++)
  {
    // Se o pivô da linha for 0
    if (m[i][i] == 0)
    {
      j = i + 1;

      // busca a próxima coluna sem pivô nulo
      while (j < n && m[i][j] == 0)
      {
        j++;
      }

      // Se houver linha j com pivô não nulo
      // Troca as linhas i e j.
      if (j < n)
      {
        _trocar_colunas(m, n, i, j);
        coluna_aux = aux[i];
        aux[i] = aux[j];
        aux[j] = coluna_aux;
        houve_troca_de_coluna = true;
      }
      else
      {
        //    Se não houver coluna para trocar, a
        // coluna é variável livre e pode ser zerada.
        for (l = 0; l < n; l++)
        {
          m[l][i] = 0;
        }
      }
    }

    // Realiza a pivotação
    if (m[i][i] != 0)
    {
      for (j = 0; j < n; j++)
      {
        // Evitando a linha do pivô
        if (j != i)
        {
          mult = -m[j][i] / m[i][i];
          m[j][i] = 0;
          // colunas anteriores ao pivô já são nulas
          for (k = i + 1; k <= n; k++)
          {
            m[j][k] += mult * m[i][k];
          }
        }
      }
    }
  }

  // Checa se precisa retornar o vetor de índices auxiliar
  if (houve_troca_de_coluna)
  {
    return aux;
  }
  else
  {
    printf("Nao houve troca de coluna\n");
    free(aux);
    return NULL;
  }
}

unsigned *metodo_pivot_completo(double **m, unsigned n)
{
  bool houve_troca_de_coluna = false;
  int i, j, k;
  double *linha_aux,
      mult,
      max;
  unsigned linha_max,
      coluna_max,
      coluna_aux,
      *index_map = (unsigned *)malloc(n * sizeof(unsigned));
  if (index_map == NULL)
  {
    printf("Vetor auxiliar não alocado\n");
    return NULL;
  }
  for (i = 0; i < n; i++)
  {
    index_map[i] = i;
  }

  for (i = 0; i < n - 1; i++)
  {
    max = 0;
    linha_max = i;
    coluna_max = i;

    // Busca o pivô, maior valor em módulo
    for (j = i; j < n; j++)
    {
      for (k = i; k < n; k++)
      {
        if (abs(m[j][k]) > max)
        {
          max = abs(m[j][k]);
          linha_max = j;
          coluna_max = k;
        }
      }
    }

    // Troca linhas
    if (linha_max != i)
    {
      linha_aux = m[i];
      m[i] = m[linha_max];
      m[linha_max] = linha_aux;
    }
    // Troca colunas
    if (coluna_max != i)
    {
      _trocar_colunas(m, n, i, coluna_max);
      coluna_aux = index_map[i];
      index_map[i] = index_map[coluna_max];
      index_map[coluna_max] = coluna_aux;
      houve_troca_de_coluna = true;
    }

    // Realiza a pivotação
    if (m[i][i] != 0)
    {
      for (j = i + 1; j < n; j++)
      {
        mult = -m[j][i] / m[i][i];
        m[j][i] = 0;

        for (k = i + 1; k <= n; k++)
        {
          m[j][k] += mult * m[i][k];
        }
      }
    }
  }

  // Checa se precisa retornar o vetor de índices auxiliar
  if (houve_troca_de_coluna)
  {
    return index_map;
  }
  else
  {
    printf("Nao houve troca de coluna\n");
    free(index_map);
    return NULL;
  }
}

double *metodo_jacobi(double **m,
                      unsigned n,
                      unsigned max_iter = _MAX_ITER,
                      unsigned max_repeat = _MAX_REPEAT,
                      double tolerancia = _ERRO_TOLERAVEL)
{
  unsigned i, j,
      iter = 0,
      contador = 0;
  double *atual = (double *)calloc(n, sizeof(double)),
         *anterior = (double *)calloc(n, sizeof(double)),
         *aux,
         soma,
         erro_acumulado;
  if (anterior == NULL)
  {
    printf("Nao foi possivel alocar vetor auxiliar\n");
    return NULL;
  }
  if (atual == NULL)
  {
    printf("Nao foi possivel alocar vetor de respostas\n");
    free(anterior);
    return NULL;
  }

  if (!e_diagonal_dominante(m, n))
  {
    printf("Matriz nao e diagonal dominante, solução pode nao convergir");
  }

  do
  {
    erro_acumulado = 0;
    for (i = 0; i < n; i++)
    {
      if (m[i][i] != 0)
      {
        soma = 0;
        for (j = 0; j < n; j++)
        {
          if (i != j)
          {
            soma += m[i][j] * anterior[j];
          }
        }
        atual[i] = (m[i][n] - soma) / m[i][i];
        erro_acumulado += abs(atual[i] - anterior[i]);
      }
    }

    iter++;
    if (erro_acumulado < tolerancia)
    {
      contador++;
    }
    else
    {
      contador = 0;
    }

    aux = anterior;
    anterior = atual;
    atual = aux;

  } while (contador < 5 && iter < max_iter);

  printf("Jacobi concluido depois de %u/%u iteracoes\n", iter - contador, max_iter);

  free(atual);
  return anterior;
}

double *metodo_gauss_seidel(double **m,
                            unsigned n,
                            unsigned max_iter = _MAX_ITER,
                            unsigned max_repeat = _MAX_REPEAT,
                            double tolerancia = _ERRO_TOLERAVEL)
{
  unsigned i, j,
      iter = 0,
      contador = 0;
  double *x = (double *)calloc(n, sizeof(double)),
         soma,
         x_anterior,
         erro_acumulado;
  if (x == NULL)
  {
    printf("Nao foi possivel alocar vetor de respostas\n");
    return NULL;
  }

  if (!e_diagonal_dominante(m, n))
  {
    printf("Matriz nao e diagonal dominante, solução pode nao convergir");
  }

  do
  {
    iter++;
    erro_acumulado = 0;
    for (i = 0; i < n; i++)
    {
      if (m[i][i] != 0)
      {
        soma = 0;
        for (j = 0; j < n; j++)
        {
          if (i != j)
          {
            soma += m[i][j] * x[j];
          }
        }
        x_anterior = x[i];
        x[i] = (m[i][n] - soma) / m[i][i];
        erro_acumulado += abs(x[i] - x_anterior);
      }
    }

    if (erro_acumulado < tolerancia)
    {
      contador++;
    }
    else
    {
      contador = 0;
    }
  } while (contador < max_repeat && iter < max_iter);

  printf("Gauss-Seidel concluido depois de %u/%u iteracoes\n", iter - contador, max_iter);
  return x;
}
