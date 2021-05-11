#include <stdio.h>
#include <stdlib.h>

#include "./matriz.h"
#include "./slsolve.h"

int main(int argc, char const *argv[])
{
  unsigned n, i;
  printf("Numero de variaveis: ");
  scanf("%d", &n);

  double **m = alocar_matriz(n, n + 1);
  if (m == NULL)
  {
    printf("Deu ruim! Falta de memoria para a matriz\n");
    return 1;
  }

  ler_matriz(m, n, n + 1);
  printf("\nMatriz original\n");
  mostrar_matriz(m, n, n + 1);

  double *x1 = metodo_jacobi(m, n);

  for (i = 0; i < n; i++)
  {
    printf("x[%d] = %10.3lf\n", i + 1, x1[i]);
  }

  double *x2 = metodo_gauss_seidel(m, n);

  for (i = 0; i < n; i++)
  {
    printf("x[%d] = %10.3lf\n", i + 1, x2[i]);
  }

  free(x1);
  free(x2);
  free(m);
  return 0;
}
