// Unions em C e C++

/**
 *      CONCEITO:   Unions são estruturas feitas para aninhar dados relacionados
 * 
 *      Uniões são um tipo abstrato de dado, semelhante a structs, podendo armazenar
 * atributos e métodos (porém este ultimo também é desaconselhado em unions).
 *      Todos os atributos da union começam na mesma posição de memória, permitindo
 * assim que a alteração de um afete os demais.
 *      O uso de unions pode ser útil para declarar variáveis que devam possuir o mesmo
 * valor porém com nomes diferentes (polimorfismo) e/ou para acessar segmentos de um
 * dado maior que exista dentro da union.
 * 
 *      TAMANHO:    Como todos os atributos possuem o mesmo endereço de início, seu tamanho é
 *                  limitado pelo tamanho do atributo de maior tipo.
*/

#include <stdio.h>

union Tipo_SquareSize {
    int side;
    int width;
    int height;
} typedef SquareSize;

union Tipo_Partes {
    unsigned char bytes[4];
    unsigned int inteiro;
} typedef Partes;

int main(void)
{
    // Declarando variável do tipo união para polimorfismo
    SquareSize square;
    square.side = 42;
    printf("\tSquare\n");
    printf("width:\t%d;\n", square.width);
    printf("height:\t%d;\n", square.height);

    // Declardando variável do tipo união para acessar partes de um inteiro
    Partes numero;
    numero.inteiro = 256 + 42;                  // o valor armazenado no inteiro ocupa 256 (1 byte) + 42
    printf("\ninteiro: %d;\n", numero.inteiro); // 298
    printf("bytes[0]: %d;\n", numero.bytes[0]); // 298 excede em 42 o tamanho do char, então 42 restam na posição 0
    printf("bytes[1]: %d;\n", numero.bytes[1]); // e +1 (de carry) é adicionado para a posição seguinte (1).
    printf("bytes[2]: %d;\n", numero.bytes[2]);
    printf("bytes[3]: %d;\n", numero.bytes[3]);

    return 0;
}