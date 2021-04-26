// Entendendo a função main em C e C++

/**
 *      C e C++ são linguagens de programação compiladas, por isso,
 * para serem executadas, são compiladas em um arquivo executável,
 * e ao ser executado, executará a chamada da função main, que
 * executará os comandos que estão dentro de seu escopo.
 *      Diz-se que o que for declarado fora do escopo da função main
 * está no escopo global.
 *      Por prática geral, a função main é do tipo inteiro (int), e
 * por isso é uma boa prática também retornar 0.
 *      Caso seja necessário forçar o fim da execução do programa
 * antecipadamente, recomenda-se usar (return -1;).
*/

int main()
{
    return 0;
}