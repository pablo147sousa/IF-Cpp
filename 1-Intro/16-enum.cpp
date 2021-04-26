// Enums em C e C++

/**
 *      CONCEITO:   São estruturas utilizadas para armazenar constantes inteiras, onde
 *                  é mais fácil compreendê-las por seu identificador que pelo seu valor.
 * 
 *      Em C, enumerações são uma forma de associar nomes a constantes do tipo inteiro,
 * por isso, em sua declaração não é necessário especificar o tipo do nome reservado e
 * não é preciso o uso de ponto e vírgula (';'), bastando apenas separar as constantes
 * por vírgula (',').
 *      É semelhante ao #define, porém, enumerações podem ser extendidas para declarar
 * multiplos valores ao mesmo tempo, além disso, enquanto #define se restringe ao escopo
 * global, enum pode se limitar a escopos locais. Os nomes listados na enumeração não
 * podem ser redeclarados dentro do escopo que existem.
 *      Caso o valor de uma dessas constantes dentro da lista não seja explicitado, por
 * atribuir o inteiro desejado à constante específica, então o valor desta será igual ao
 * valor da constante anterior + 1, e no caso da primeira constante, será 0.
 *      Ao declarar uma variável do tipo enum, ela só poderá assumir os valores permitidos,
 * e na atribuição esse valor poderá ser um inteiro ou o nome da constante declarada na enum.
 *      
 *      OBS:    ao atribuir valores inteiros para constantes da enumeração, esses inteiros
 *              podem ser do tipo int ou do tipo char, pois ambos são inteiros.
*/

#include <stdio.h>

enum Tipo_Escape
{
    nullChar = '\0',
    alert = '\a',
    backSpace = '\b',
    tab = '\t',
    newLine = '\n'
} typedef Escape;

int main(void)
{
    Escape character = tab;
    printf("tab(\\t): A%cA;\n", character);

    return 0;
}