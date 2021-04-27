#include <iostream>
#include <stdio.h>

#include "./matriz.h"
#include "./slsolve.h"

int main()
{
  unsigned n;
  double **m, *x;

  std::cout << "Numero de variaveis: ";
  std::cin >> n;

  m = alocar_matriz(n, n + 1);
  x = (double *)malloc(sizeof(double) * n);

  if (m == NULL || x == NULL)
  {
    std::cout << "Deu ruim! Falta de memoria" << std::endl;
    return 1;
  }

  ler_matriz(m, n, n + 1);
  mostrar_matriz(m, n, n + 1);

  metodo_gauss(m, n);
  mostrar_matriz(m, n, n+1);

  int tipo = sub_retro(m, n, x);
  if (tipo == 2)
  {
    printf("SL Incompatível\n");
  }
  else
  {
    printf("SL %sdeterminado\n", tipo ? "in" : "");
    for (unsigned i = 0; i < n; i++)
    {
      printf("x[%d] = %7.3lf\n", i + 1, x[i]);
    }
  }

  return 0;
}
