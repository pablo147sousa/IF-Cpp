// Funções em C e C++

/**
 *      Funções são blocos de código contendo uma sequência de comandos que são executados
 * quando forem chamados. Elas podem ter um retorno especificado e parâmetros de entrada.
 *      Um exemplo de função pode ser descrita como a propria main(), que é chamada sempre
 * que o programa compilado é executado.
 *      O tipo do retorno da função é especificado sempre que a função for declarada, e caso
 * a função não tenha retorno, declara-se com o tipo void.
 * 
 * EXEMPLO:
 * tipo_do_retorno nome_da_função( parâmetros )
 * {
 *      algoritmo;
 * }
 * 
 * OBS: Funções sem parâmetro em C requerem void entre os parêntesis, em C++ isto é opcional.
 * 
 *      É possível realizar a sobrecarga de funções, que é quando existem várias funções com
 * o mesmo nome, porém com parâmetros diferentes, pois é a forma de como os parâmetros estão
 * dispostos na chamada da função que determina qual das funções de mesmo nome será chamada.
*/

#include <stdio.h>

void Alfabeto(char letra)
{
    int posicaoLetra = letra;
    printf("\t26 primeiras letras a partir da letra %c de acordo com tabela ASCII\n", letra);
    for (int i = posicaoLetra; i < posicaoLetra + 26; i++)
    {
        printf("%c, \n", i);
    }
}

void Alfabeto(void)
{
    int posicaoA = 'a';

    printf("\tAlfabeto\n");
    for (int i = posicaoA; i < posicaoA + 26; i++)
    {
        printf("%c, \n", i);
    }
}

int main(void)
{
    Alfabeto('a');
    printf("\n\n");
    Alfabeto();

    return 0;
}