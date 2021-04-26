// Alocação de memória em C e C++

/**
 *      Em C e C++, a atribuição de valor ocorre por cópia, por isso as
 * alterações que uma variável sofre estão restringidas ao escopo em que
 * ocorrem, porém, essa barreira pode ser superada se a alteração ocorrer
 * na memória em que está localizada a variável, sendo necessário pelo
 * menos a passagem da referência da variável.
 * 
 *      Trabalhar com alocação memória em C e C++, através de operações
 * com ponteiros, endereços e memória do sistema, permite requerir mais
 * memória para aumentar um vetor ou alterar uma variável que esteja em
 * um escopo diferente do escopo da operação que realizou essa alteração.
 *      Alocação dinâmida de memória em C e C++ para alterar a memória
 * sendo utilizada durante tempo de execução requer incluir a biblioteca
 * <stdlib.h>, que possui as funções malloc(), calloc(), realloc() e free().
 * 
 *      MALLOC: tipo *pointer = (tipo *) malloc(espaço)
 *                  Memory ALLOCation, ou malloc() é usado para requerir
 *              um espaço na memória, ela retorna um ponteiro (void *),
 *              que por isso precisa ter seu tipo convertido para o que
 *              é requerido, que aponta para uma posição na memória
 *              reservada, de mesmo tamanho do qual foi passado por
 *              parâmetro, e caso isso não seja possível, retorna NULL.
 * 
 *      CALLOC: tipo *pointer = (tipo *) calloc(inteiro, espaço)
 *                  Contiguous ALLOCation, ou calloc() é usado para reservar
 *              um espaço na memória, de forma semelhante à função malloc,
 *              calloc(inteiro, espaço) equivale a malloc(inteiro * espaço)
 *              e caso isso não seja possível, retorna NULL.
 * 
 *      REALLOC: pointer = realloc(pointer, novoespaço)
 *               array = realloc(array, novoespaço)
 *                  RE-ALLOCation, ou realloc() é usado para alterar o espaço
 *              reservado por um ponteiro, pode ser usado para aumentar ou
 *              diminuir o tamanho de um vetor, e caso isso não seja possível,
 *              retorna NULL.
 * 
 *      FREE: free(pointer)
 *                  Ao alocar memória dinamicamente com as funções malloc,
 *              calloc e realloc, um espaço na memória fica reservado por
 *              elas até o fim da execução do programa, e para evitar esse
 *              desperdício de memória, é útil usar a função free para
 *              liberar esse espaço reservado.
 *                  É preciso Desalocar memória quando esta não é mais necessária
 *              a fim de evitar problemas.
*/

#include <stdio.h>
#include <stdlib.h> // Necessária para as funções de alocação dinâmica e NULL

/// Troca o valor presente numa variável pela outra
void Troca_Int(int *value_1, int *value_2)
{
    int auxiliar = *value_1;
    *value_1 = *value_2;
    *value_2 = auxiliar;
    printf("Troca realizada\n");
}

int main()
{
    /// Exemplo de como através de ponteiros é possível alterar variáveis de escopo diferente
    int a = 4, *pa = &a,
        b = 2, *pb = &b;

    printf("a: %d;\tb: %d;\n", a, b);
    Troca_Int(pa, pb);
    printf("a: %d;\tb: %d;\n", a, b);

    /**
     *  AVISO: SIGA O PADRÃO:   => alocar memória ao ponteiro
     *                          => checkar se alocação foi bem sucedida
     *                          => utilizar o ponteiro
     *                          => liberar o ponteiro após usar
     *                          => resetar para onde o ponteiro aponta
     * 
     *      A função malloc recebe como parâmetro de entrada um (unsigned int), indicando a
     * quantiadade de Bytes necessários para reservar, o que por vezes também depende do tipo
     * e da quantidade de posições.
     *      Para alocar memória para um vetor utilizando a função malloc, usa-se como parâmetro
     * de entrada o tamanho do tipo do vetor vezes o número de posições, pois assim, o sistema
     * reservará uma posição na memória e as consecutivas para este fim.
     * 
     *      EXEMPLO: tipo *nome = (tipo *) malloc(num_posicoes * sizeof(tipo));
     * 
     *      É necessário usar (tipo *) antes de atribuir o retorno de malloc para realizar o
     * typecasting, pois, malloc retorna um ponteiro (void *) genérico que precisa ser convertido
     * para o tipo desejado da variável.
     *      Caso tente usar posições que não foram reservadas para este uso, você corre o risco
     * de sobrescrever algum dado importante para o sistema.
     *      Caso tente alocar memória para um vetor de caracteres (string), deve-se adicionar mais
     * uma unidade além da quantidade de caracteres, poisa após os caracteres deverá existir um
     * caractere nulo ('\0') indicando o fim do vetor.
     * 
     *      EXEMPLO: char *nome = (char *) malloc(num_posicoes * sizeof(char) + 1);
    */

    /// EXEMPLO: Como Alocar memória com função malloc para uma variável
    // malloc retorna um ponteiro (void *), por isso é necessário o typecasting para (int *)
    int *variavel = (int *)malloc(sizeof(int));
    if (variavel == NULL)
    {
        printf("Falha na Alocação de memória\n");
        return -1; // aplicação encerrada
    }
    *variavel = 42;

    free(variavel); // Liberando espaço alocado
    variavel = NULL; // Resetando ponteiro

    /// EXEMPLO: Como alocar memória em tempo de execução para um vetor
    int num_posicoes = 4;
    int *vetor = (int *)malloc(num_posicoes * sizeof(int));
    if (vetor == NULL)
    {
        printf("Falha na Alocação de memória\n");
        return -1; // aplicação encerrada
    }

    for (int i = 0; i < num_posicoes; i++)
    {
        vetor[i] = num_posicoes * i; // Preenchendo o vetor
        printf("Endereco: %p;\tValor: %d;\tPosicao: %d;\n", vetor + i, vetor[i], i);
    }

    free(vetor); // Liberando o espaço alocado após utilização
    vetor = NULL; // Modificando para onde o vetor aponta

    return 0;
}