// Implementação de algoritmos e operações com matrizes

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 *    Aloca dinamicamente uma matriz com a dimensões definidas,
 * caso não consiga, retorna NULL.
*/
double **alocar_matriz(unsigned n_linhas, unsigned n_colunas)
{
  double **matriz = NULL;
  unsigned i = 0, j = 0;

  matriz = (double **)malloc(sizeof(double *) * n_linhas);

  if (matriz == NULL)
  {
    return NULL;
  }

  for (i = 0; i < n_linhas; i++)
  {
    matriz[i] = (double *)malloc(sizeof(double) * n_colunas);

    // Caso não consiga alocar uma coluna, libera tudo.
    if (matriz[i] == NULL)
    {
      for (j = 0; j < i; j++)
      {
        free(matriz[j]);
      }
      free(matriz);
      return NULL;
    }
  }
  return matriz;
}

// Lê valores para uma matriz de double passada.
void ler_matriz(double **matriz, unsigned n_linhas, unsigned n_colunas)
{
  unsigned i, j;

  for (i = 0; i < n_linhas; i++)
  {
    for (j = 0; j < n_colunas; j++)
    {
      printf("M[%d][%d]: ", i + 1, j + 1);
      scanf("%lf", &matriz[i][j]);
    }
  }
}

// Imprime os valores de uma matriz com as dimensões especificadas
void mostrar_matriz(double **matriz, unsigned n_linhas, unsigned n_colunas)
{
  unsigned i, j;

  for (i = 0; i < n_linhas; i++)
  {
    printf("[");
    for (j = 0; j < n_colunas; j++)
    {
      printf("%10.3lf", matriz[i][j]);
    }
    printf("]\n");
  }
}

void _trocar_colunas(double **matriz, unsigned n_linhas, unsigned col_a, unsigned col_b)
{
  if (matriz != NULL)
  {
    double aux;
    for (unsigned i = 0; i < n_linhas; i++)
    {
      aux = matriz[i][col_a];
      matriz[i][col_a] = matriz[i][col_b];
      matriz[i][col_b] = aux;
    }
  }
}

// Verifica se a matriz é Triângular Superior
bool e_tri_superior(double **matriz, unsigned n_linhas)
{
  for (int i = 0; i < n_linhas; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (matriz[i][j] != 0.0)
      {
        return false;
      }
    }
  }
  return true;
}

// Verifica se a matriz é Triângular Inferior
bool e_tri_inferior(double **matriz, unsigned n_linhas)
{
  for (int i = 0; i < n_linhas; i++)
  {
    for (int j = i + 1; j < n_linhas; j++)
    {
      if (matriz[i][j] != 0.0)
      {
        return false;
      }
    }
  }
  return true;
}

bool e_diagonal(double **matriz, unsigned n_linhas)
{
  unsigned i, j;
  for (i = 0; i < n_linhas; i++)
  {
    for (j = 0; j < n_linhas; j++)
    {
      // Checa a matriz, exceto n a diagonal principal
      if (j != i && matriz[i][j] != 0)
      {
        return false;
      }
    }
  }

  return true;
}
