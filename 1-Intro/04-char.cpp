// Caracteres (char) em C e C++

/**
 *      Cada caractere está relacionado a um número inteiro,
 * de acordo com a tabela ASCII, incluindo os caracteres de
 * controle, quebra de linha, espaçamentos e backspace.
 *      Em C e C++ um caractere é delimitado por aspas (' '),
 * enquanto strings (sequência de caracteres) são delimitados
 * por aspas duplas (" ").
 *      Caracteres de controle são formados por barra invertida
 * (\) seguido de algum caractere, essa combinação é considerada
 * um caractere único, por exemplo: '\n'.
*/

/**
 * Principais Caracteres de Controle
 *  - '\0': null (representa o ultimo caractere de uma string)
 *  - '\a': alert (faz a máquina emitir um alerta sonoro)
 *  - '\b': backspace (apaga o caractere anterior)
 *  - '\f': feed page (limpa a tela do prompt)
 *  - '\n': feed line (pula para a próxima linha)
 *  - '\t': tab (tabulação horizontal)
 *  - '\v': tab (tabulação vertical)
*/

#include <stdio.h>

int main()
{
    printf("ASCII Table\n");
    for (int i = 0; i < 256; i++)
    {
        printf("int: %d;\thexadecimal: %x;\tchar: %c;\n", i, i, i);
    }
    return 0;
}