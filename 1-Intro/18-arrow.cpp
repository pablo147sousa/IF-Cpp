// Operador arrow (->) em C++

/**
 *      Quando se tem um tipo abstrato de dado (como classes e structs), seus valores estão aninhados
 * aninhados dentro deles, e para não usar muita memória, é mais eficiente salvar o endereço da variável
 * no qual cada dado está aninhado.
 *      Para acessar seus valores, uma forma é desreferenciar o endereço e acessar por operador ponto,
 * ou de forma mais simples, utilizar o operador arrow que possui o mesmo funcionamento (ver linha 28).
*/

#include <stdio.h>

struct Estrutura
{
    int number = 42;
    char character = 'C';
} typedef TEstrutura;

int main(int argc, char const *argv[])
{
    TEstrutura exemplo = {24, 'A'},
               *PointerExemplo = &exemplo;

    // Acessando por exemplo (com operador ponto ['.'])
    printf("number: %d;\tcharacter: %c;\n", exemplo.number, exemplo.character);

    // Acessando por pointerExemplo (com operador DeReference ['*'] e com operador arrow ['->'])
    printf("number: %d;\tcharacter: %c;\n", (*PointerExemplo).number, PointerExemplo->character);

    return 0;
}