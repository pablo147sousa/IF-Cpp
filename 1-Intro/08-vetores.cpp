// Vetores em C e C++

/**
 *      Vetores podem armazenar mais de uma variável, possuem tamanho fixo
 * (definido no contexto da sua declaração) e são homogêneos (só armazenam
 * um mesmo tipo de dado).
 *      Para declarar um vetor, é semelhante ao declarar uma variável,
 * incluindo também colchetes após o nome e um número inteiro positivo entre
 * os colchetes, indicando a quantidade de variáveis que poderá armazenar.
 * 
 *      EXEMPLO: tipo nome[tamanho];
 * 
 *      A contagem de posições de um vetor começa a partir da posição 0, então,
* em um vetor de tamanho n, poderão ser usadas as posições 0 até n - 1.
 *      Um vetor de caracteres é chamado de string, e é delimitado por aspas
 * duplas (" ").
 * 
 *      OBS: vetor[posição] é equivalente a posição[vetor];
*/

#include <stdio.h>

int main()
{
    // Declaração de vetores
    int c = 0, i = 0,
        vetor_um[3],
        vetor_dois[3] = {},
        vetor_tres[3] = {2, 1};
    for (i = 0; i < 3; i++)
    {
        printf("vetor_um[%d]: %d;\tvetor_dois[%d]: %d;\tvetor_tres[%d]: %d;\n", i, vetor_um[i], i, vetor_dois[i], i, vetor_tres[i]);
    }
    /**
     *      vetor_um declarado, porém não inicializado, devido a isso,
     * em suas posições haverão números "aleatórios", considerados como lixo.
     * 
     *      vetor_dois declarado e inicializado, porém sem nenhum valor
     * especificado, então nessas posições terão valor 0.
     * 
     *      vetor_tres declarado e inicializado com valor 2 na posição 0,
     * e valor 1 na posição 1, e como a posição 2 não foi explicitada,
     * terá o valor 0 armazenado.
    */

    char string[8] = "palavra";
    while (string[c] != '\0')
    {
        printf("%c", string[c]);
        c++;
    }
    printf("\n");
    /**
     *      Um vetor de caracteres, popularmente conhecido como string, armazena
     * em cada posição um caractere, contudo, é necessário lembrar que a ultima
     * posição contenha um caractere nulo, '\0'.
     *      O vetor string possui 8 posições, pois é uma posição para cada caractere
     * de "palavra" + 1 posição para o caractere nulo indicando o fim da string;
    */

    return 0;
}