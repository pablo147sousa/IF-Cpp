// Manipulação de arquivos de texto em C e C++

/**
 * 
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  unsigned n_row, n_col;
  printf("informe o número de linhas: ");
  scanf("%u", &n_row);

  printf("informe o número de colunas: ");
  scanf("%u", &n_col);

  double **mat = (double **)malloc(n_row * sizeof(double *));
  if (mat == NULL)
  {
    printf("Não foi possível alocar matriz\n");
    return 1;
  }
  for (unsigned i = 0; i < n_row; i++)
  {
    mat[i] = (double *)malloc(n_col * sizeof(double));
    if (mat[i] == NULL)
    {
      for (unsigned j = 0; j <= i; j++)
      {
        free(mat[j]);
      }
      printf("Não foi possível alocar matriz\n");
      return 1;
    }
  }

  for (unsigned i = 0; i < n_row; i++)
  {
    for (unsigned j = 0; j < n_col; j++)
    {
      printf("matriz[%u][%u]: ", i, j);
      scanf("%lf", &mat[i][j]);
    }
  }

  FILE *arq = fopen("./20-teste_matriz.txt", "w");
  if (arq == NULL)
  {
    printf("Não foi possível criar arquivo!\n");
    return 1;
  }

  fprintf(arq, "%u %u\n", n_row, n_col);
  for (unsigned i = 0; i < n_row; i++)
  {
    for (unsigned j = 0; j < n_col; j++)
    {
      fprintf(arq, "%.3lf ", mat[i][j]);
    }
    fprintf(arq, "\n");
  }
  fclose(arq);

  return 0;
}
