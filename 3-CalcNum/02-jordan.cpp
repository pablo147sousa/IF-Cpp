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

  ler_matriz(m, n, n + 1);
  printf("Matriz original\n");
  mostrar_matriz(m, n, n + 1);

  trocas = metodo_jordan(m, n);
  printf("Matriz apos metodo de jordan\n");
  mostrar_matriz(m, n, n+1);

  if (trocas != NULL)
  {
    printf("Colunas trocadas:\n");
    for (unsigned i = 0; i < n; i++)
    {
      if (trocas[i] != i)
      {
        printf("Coluna [%d] trocada com coluna [%d]\n", i + 1, trocas[i] + 1);
      }
    }
    free(trocas);
  }
  
  free(m);
  return 0;
}
