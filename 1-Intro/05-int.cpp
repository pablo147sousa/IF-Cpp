// Dados inteiros (int) em C e C++

/**
 *      O tipo int representa os Inteiros (integers),
 * e dependendo da máquina, seu tamanho padrão pode ser
 * 32 bits, porém, é garantido ao menos 16 bits.
 *      Seu tamanho também pode variar devido aos tipos
 * short, long, signed e unsigned. Sort e long podem
 * dobrar ou reduzir pela metade o tamanho do tipo,
 * enquanto signed e unsigned definem os intervalos
 * que o tipo abrange.
 *      Com inteiros é possível realizar operações
 * aritméticas básicas, como soma, subtração, divisão,
 * multiplicação e módulo (resto da divisão).
*/

/**
 * Operadores
 *  - (+) - soma;
 *  - (-) - subtração;
 *  - (*) - multiplicação;
 *  - (/) - divisão;
 *  - (%) - módulo;
*/

/**
 * OBS: se ao menos um dos operandos da divisão for
 *      um número de ponto flutuante, o resultado será
 *      um número de ponto flutuante.
*/

#include <stdio.h>

int main()
{
    int resultado = 4 / 2;
    return 0;
}