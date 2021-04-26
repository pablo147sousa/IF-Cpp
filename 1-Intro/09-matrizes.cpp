// Matrizes em C e C++

/**
 *      Matrizes podem ser entendidos como vetores multidimensionais,
 * ou como vetores de vetores, ou seja, vetores que possuem vetores em
 * cada posição.
*/

#include <stdio.h>

int main()
{
    // Declaração de Matrizes Unidimensionais (Vetores)
    int vetor[6] = {0, 1, 2, 3, 4, 5};

    // Declaração de Matrizes Bidimensionais (Matriz)
    int matriz_forma_1[2][3] = {{0, 1, 2}, {3, 4, 5}},
        matriz_forma_2[2][3] = {0, 1, 2, 3, 4, 5};

    // OBS: O processo pode ser extendido para n dimensões (limitado pela máquina);

    /**
     *      Em C e C++, na prática, matrizes n-dimensionais são equivalentes a vetores lineares.
     *      É como se cada dimensão tivesse um peso
     * 
     * EXEMPLO: (tipo vetor[2 * 3];) é equivalente a (tipo matriz[2][3];)
     *      - Ambos terão 6 posições;
     *      - Dado o elemento na matriz[1][1], para acessar o mesmo tratando a matriz como um
     *          vetor, faz-se o cálculo com base no tamanho declarado na matriz:
     *              - (número de linhas) * (posição da linha) + (número de colunas) * (posição da coluna);
     *              - (2 * 1) + (3 * 1) = 5;
     *              - (matriz[1][1]) == (matriz[0][5]);
    */
    printf("matriz[1][1]: %d;\tmatriz[0][5]: %d;\n", matriz_forma_1[1][1], matriz_forma_1[0][5]);

    /**
     *       Para descobrir quantas posições uma vetor possui,
     * ao utilizar a palavra reservada sizeof, ela retornará o
     * tamanho em Bytes, que além de variar conforme o tamanho
     * do vetor, também muda dependendo do tamanho do tipo que
     * é armazenado. Nesse caso, também é necessário descobrir
     * o tamanho do tipo para levar em consideração, por isso:
     * 
     * int tamanho_do_vetor = (sizeof vetor)/(sizeof tipo_do_vetor)
    */
    int tamanho_do_vetor = sizeof(vetor) / sizeof(int);
    printf("O tamanho do vetor: %d;\n", tamanho_do_vetor);

    return 0;
}
