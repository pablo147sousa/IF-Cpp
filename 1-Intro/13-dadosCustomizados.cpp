// Tipos de dados Customizados em C e C++

/**
 *      Tipos de dados customizados, abstratos ou definidos pelo usuário, são estruturas de dados
 * criados pelo usuário (programador) e que possuem características próprias, tendo como objetivo
 *  criar novos tipos para simplificar a leitura de código e aninhar dados.
 *      Para instanciar uma variável do tipo struct, union ou enum, é preciso antes definí-la,
 * declarar quais variáveis cada tipo possui.
 *      Em C e C++ existem 3 tipos de dados abstratos:
 *          - STRUCT:;
 *          - UNION:;
 *          - ENUM:;
 * 
 * OBS: Em C++, structs e unions permitem funções e valores iniciais em sua declaração, diferente de C. 
*/

#include <stdio.h>

int main()
{
    /// EXEMPLO: Declarando struct, union e enum
    struct Estrutura
    {
        /* data */
    };

    union Uniao
    {
        /* data */
    };
    
    enum Enumeracao
    {
        /* data */
    };

    /// EXEMPLO: Instanciando struct, union e enum

    struct Estrutura varEstrutura;
    union Uniao varUniao;
    enum Enumeracao varEnumeracao;

    /**
     *      Para ter menos trabalho e não ter que digitar duas palavras sempre que
     * for instanciar uma variável de tipo abstrato, recomeda-se utilizar
     * (typedef novoNome) antes de ';' ao declarar o tipo.
    */
    
    return 0;
}