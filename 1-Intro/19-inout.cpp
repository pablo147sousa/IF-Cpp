// Entrada e Saída de dados padrão em C e C++

/**
 *      Por padrão, ambas as linguagens não possuem uma função para entrada e saída de dados no console,
 * isso é possível por meio da inclusão de headers e bibliotecas.
 *      Em C, o header padrão para tais funções é a stdio.h
 *      Em C++, a biblioteca padrão é a iostream
*/

#include <stdio.h>  // Padrão em C
#include <iostream> // Padrão em C++

int main(int argc, char const *argv[])
{
    // InOut em C
    int inC;

    scanf("%d", &inC);
    /**
     *      Recebe como primeiro parâmetro uma string literal apenas com as [N] format flags dos dados de input,
     * os [N] parâmetros seguintes são os endereços das variáveis para se armazenar os dados, cujo os tipos devem
     * estar na mesma ordem que os listados nas flags. A função retorna o número de casos que deram certo armazenar
     * o input na variável.
    */

    printf("Saída em C: %d\n", inC);
    /**
     *      Recebe como primeiro parâmetro uma string literal que pode possuir format flags, e os parâmetros
     * seguintes são os valores respectivos às formats flags, podendo ser constantes, expressões, variáveis e
     * chamada de funções (que possuem retorno).
    */

    /**
     * FORMATFLAGS: %[parameter$][flags][width][.precision][length]type
     * 
     * veja mais em: https://en.wikipedia.org/wiki/Printf_format_string
    */

    // InOut em C++
    int inCpp = 0;

    std::cin >> inCpp; // Recebe após cada ">>" a variável na qual será armazenada o input

    std::cout << "Saída em C++: " << inCpp << std::endl;
    /**
     *      Recebe após cada ">>" uma variável, constantes, expressões ou funções com retorno cujo valor será
     * imprimido no console.
    */
    
    return 0;
}