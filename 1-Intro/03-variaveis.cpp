// Variáveis em C e C++

/**
 *      Variáveis são espaços na memória RAM
 * reservados para armazenar dados que serão
 * criados e alterados em tempo de execução.
 *      Após declarar uma variável, seu valor
 * inicial é aleatório, por isso e recomendável
 * atribuir um valor inicial após sua declaração.
 * 
 * Variáveis possuem:
 *      - Identificação (nome, assinatura)
 *      - Endereço      (inteiro representando a posição na memória)
 *      - Tipo          (ex.: int, char...)
 *      - Tamanho       (quantidade de espaço reservado na memória)
 *      - Valor         (o dado que será atribuído à variável)
*/

#include <stdio.h>

int main()
{
    // Declarando variável
    char caractere = 'c';

    // Declarando múltiplas variáveis de mesmo tipo
    int numero = 0, inteiro = 24;

    // OBS: é possível realizar atribuições múltiplas em uma mesma linha
    numero = inteiro = 42;

    return 0;
}
