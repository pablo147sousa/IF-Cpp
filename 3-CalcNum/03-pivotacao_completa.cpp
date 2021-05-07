#include <stdio.h>
#include <stdlib.h>

#include "./matriz.h"
#include "./slsolve.h"

int main(int argc, char const *argv[])
{
  unsigned n, *trocas;
  printf("Numero de variaveis: ");
  scanf("%d", &n);

  double **m;
  m = alocar_matriz(n, n + 1);
  if (m == NULL)
  {
    printf("Deu ruim! Falta de memoria para a matriz\n");
    return 1;
  }

  double *x = (double *)calloc(n, sizeof(double));
  if (x == NULL)
  {
    free(m);
    printf("Deu ruim! Falta de memória para vetor de variaveis\n");
    return 1;
  }

  ler_matriz(m, n, n + 1);
  printf("\nMatriz original\n");
  mostrar_matriz(m, n, n + 1);

  trocas = metodo_pivot_completo(m, n);
  printf("\nMatriz apos metodo da Pivotacao Completa\n");
  mostrar_matriz(m, n, n + 1);

  int tipo = sub_retro(m, n, x);
  switch (tipo)
  {
  case -1:
    printf("Sl nao e TS\n");
    break;

  case 0:
  case 1:
    printf("SL %sdeterminado\n", tipo ? "in" : "");
    break;

  case 2:
    printf("SL incompativel\n");
    break;

  default:
    break;
  }

  if (trocas != NULL)
  {
    printf("\nColunas trocadas:\n");
    for (unsigned i = 0; i < n; i++)
    {
      if (trocas[i] != i)
      {
        printf("Coluna [%d] e variavel x[%d]\n", i + 1, trocas[i] + 1);
      }
    }
    for (int i = 0; i < n; i++)
    {
      printf("x[%d] = %10.3lf\n", trocas[i] + 1, x[i]);
    }
    free(trocas);
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      printf("x[%d] = %10.3lf\n", i + 1, x[i]);
    }
  }

  free(x);
  free(m);
  return 0;
}
