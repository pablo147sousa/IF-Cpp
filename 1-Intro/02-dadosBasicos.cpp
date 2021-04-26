// Tipos de dados Básicos em C e C++

/**
 *      Dados em C e C++ são armazenados na memória em bits, e para
 * o programador são representados através de estruturas de dados.
 *      as estruturas de dados Básicas podem ser dividas em dois tipos,
 * as de tipo inteiro, e as de tipo ponto flutuante.
*/

/* Tipo             | Tamanho comum em bits     |
 *
 * char             | 1 Byte    - 8 bits        | Caractere
 * int              | 2 Bytes   - 16 bits       | número inteiro
 * float            | 4 Bytes   - 32 bits       | número de ponto flutuante (com 6 casas decimais de precisão)
 * double           | 8 Bytes   - 64 bits       | número de ponto flutuante (com 15 casas decimais de precisão)
 * long double      | 12 Bytes  - 96 bits       | número de ponto flutuante (com 19 casas decimais de precisão)
 * 
 * short type       | metade do tamanho do type |
 * long type        | dobro do tamanho do type  |
 * signed type      | intervalo centrado em 0   |
 * unsigned type    | intervalo começa em 0     |
 * 
 * se type não for explicitado, será considerado int
*/

/**
 * Por padrão, não existe tipo booleano em C, porém,
 * 1 e 0 podem ser considerados para esse fim
*/

#include <stdio.h>

int main()
{
    printf("size of char: %d byte\n", sizeof(char));
    printf("size of int: %d bytes\n", sizeof(int));
    printf("size of float: %d bytes\n", sizeof(float));
    printf("size of double: %d bytes\n", sizeof(double));
    printf("size of short: %d bytes\n", sizeof(short));
    printf("size of long: %d bytes\n", sizeof(long));
    printf("size of signed: %d bytes\n", sizeof(signed));
    printf("size of unsigned: %d bytes\n", sizeof(unsigned));
    printf("size of long long: %d bytes\n", sizeof(long long));
    printf("size of long double: %d bytes\n", sizeof(long double));

    return 0;
}