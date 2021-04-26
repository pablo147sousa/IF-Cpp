// Implementação de algoritmos de resolução de sistemas lineares

/**
 * Algoritmos para resolução de sistemas lineares recebem a
 * matriz aumentada e um ponteiro para o vetor de solução e
 * retornam o tipo da resposta.
 *    Se o SL não for TS, o tipo é -1 e x será NULL.
 *    Se o SL for determinado, o tipo é 0, x será o vetor
 * com as soluções.
 *    Se o SL for indeterminado, o tipo é 1, x será uma
 * solução, definindo com 0 as variáveis lívres.
 *    Se o SL for incompatível, o tipo é 2 e x será NULL.
*/

#include <math.h>


/**
 *    Algoritmo de substituição retroativa.
 * 
 * \param m matriz aumentada de coeficientes;
 * \param n número de linhas da matriz;
 * \param x vetor de n posições para armazenar o resultado;
 * 
 * \return o tipo de resposta:
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
    for (j = i + 1; j < n; j++)
    {
      soma += m[i][j] * x[j];
    }
    if (m[i][i] == 0)
    {
      if (m[i][n] == soma)
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
