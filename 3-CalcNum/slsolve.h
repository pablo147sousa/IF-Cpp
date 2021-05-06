// Implementação de algoritmos de resolução de sistemas lineares

#pragma once
#include <math.h>

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
 * 
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

  unsigned *aux = (unsigned *)calloc(n, sizeof(unsigned));
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
        aux[i] = j;
        aux[j] = i;
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
          // colunas anteriores ao pivô já são nulas
          for (k = i; k <= n; k++)
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
