// Ponteiros e Endereços em C e C++

/**
 *      C e C++ permitem manipular variáveis através da memória, ou seja,
 * em tempo de execução, as variáveis são declaradas e com isso um espaço
 * na memória torna-se reservado para ela armazenar seus valores, então é
 * correto dizer que todas as variáveis possuem um endereço na memória.
 * 
 *      Ponteiros são variáveis que têm como valor o endereço de memória
 * para o qual elas "apontam". Ponteiros são considerados tipos derivados,
 * pois só podem apontar para o endereço de uma variável de mesmo tipo de
 * sua declaração.
 *      Para cada tipo, existe um ponteiro específico que também é um outro
 * tipo, e assim, conclui-se que para cada tipo (type) existe um respectivo
 * ponteiro (type *), e analogamente, para o tipo (type *) existe o ponteiro
 * de tipo (type **) e assim infinitamente.
 * 
 *      Endereços são valores que contém a localização de memória no qual
 * sua respectiva variável está reservada e por isso não podem ser alterados.
 * 
 *      O operador '*' (asterisco), também usado para multiplicação, é usado
 * para declarar ponteiros, e nesse caso é chamado de Operador de Derreferência
 * (Dereference Operator).
 * 
 *      O operador '&' (letra 'E' Comercial), é utilizado para se obter o
 * endereço de memória de uma variável, ele é chamado de Operador de Referência
 * (Reference Operator).
 * 
 *      O nome de um vetor sem nenhum índice representa o endereço do primeiro
 * elemento do vetor, ou seja, (vetor) == (&vetor[0])
 * 
 *      Ao realizar comparações entre ponteiros, está sendo comparado as posições
 * de memória, ou seja, se ponteiros apontam para o mesmo endereço ou se estão em
 * posições "mais adiante na memória"
*/

#include <stdio.h>
#define VALOR 42

int main(void)
{
    /**
     * EXEMPLIFICANDO: Ponteiro para variáveis e Ponteiros para ponteiros
    */
    int variavel = VALOR;      // Declara uma variável (do tipo int) que tem armazenada um valor, no caso, 42;
    int *ponteiro = &variavel; // Declara um ponteiro (do tipo int *) que aponta para o endereço de variavel;
    int **pointer = &ponteiro; // Declara um ponteiro (do tipo int **) que aponta para o endereço de ponteiro;

    printf("Endereço de variavel: %p;\tValor armazenado em variavel: %d;\n", &variavel, variavel);
    printf("Endereço de variavel: %p;\tValor armazenado em variavel: %d;\n", ponteiro, *ponteiro);
    printf("Endereço de variavel: %p;\tValor armazenado em variavel: %d;\n", *pointer, **pointer);
    printf("Endereço de ponteiro: %p;\tValor armazenado em ponteiro: %p;\n", pointer, *pointer);

    /**
     * EXEMPLIFICANDO: Ponteiro para vetores
    */
    int vetor[4] = {3, 2, 1, 0}; // Declara um vetor (do tipo int) que armazena valores inteiros;
    int *ponteiroVetor = vetor;  // Declara um ponteiro (do tipo int *) que aponta para o primeiro elemento do vetor
    int tamanho_do_vetor = sizeof(vetor) / sizeof(vetor[0]);

    // Formas de acesso
    int array[4] = {3, 2, 1, 0},
        *parray = array;

    printf("\nFormas de acessar o Endereço da primeira posição do array:\n");
    printf("array: %p;\t&array[0]: %p;\t&0[array]: %p;\n", array, &array[0], &0 [array]);

    printf("\nFormas de acessar um valor de um array:\n");
    printf("através de um array:\tarray[2]: %d;\t2[array]: %d\n", array[2], 2 [array]);
    printf("através de um ponteiro:\t*(parray + 2): %d;\tparray[2]: %d;\t2[parray]: %d;\n", *(parray + 2), parray[2], 2 [parray]);
    /**
     *      OBS: Para acessar posições consecutivas do array através de parray, é possível usar a
     *           mesma notação de como se acessa um array comum;
     *      EXEMPLO: (*parray) é equivalente a (parray[0]) ou (0[parray]);
    */

    // Formas de Percorrer vetores
    printf("\n\tPercorrendo o vetor sem alterar o ponteiro\n");
    for (int i = 0; i < tamanho_do_vetor; i++)
    {
        printf("elemento em vetor[%d]: %d;\tponteiro: %p;\n", i, *(ponteiroVetor + i), ponteiroVetor);
    }

    printf("\n\tPercorrendo o vetor alterando o ponteiro\n");
    for (int i = 0; i < tamanho_do_vetor; i++)
    {
        printf("elemento em vetor[%d]: %d;\tponteiro: %p;\n", i, *ponteiroVetor++, ponteiroVetor);
        // OBS: Ao final do laço, o ponteiro apontará para uma posição na memória que não corresponde ao vetor
    }
    ponteiroVetor = vetor; // Redefinindo ponteiro para posição inicial

    printf("\n\tPercorrendo o vetor pelo vetor\n");
    for (int i = 0; i < tamanho_do_vetor; i++)
    {
        printf("elemento em vetor[%d]: %d;\n", i, vetor[i]);
    }

    return 0;
}