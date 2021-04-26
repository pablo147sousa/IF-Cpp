// Structs em C e C++

/**
 *      CONCEITO:   structs são estruturas simples feitas com intenção de aninhar
 *                  variáveis em uma só, por isso não é aconselhável tratar elas
 *                  como sendo classes criando métodos e interações como se suas
 *                  variáveis fossem objetos.
 * 
 *      Structs, Estruturas ou Resgistros, sãó úteis para aninhar dados, sejam eles
 * de mesmo tipo ou não, sejam de tipos primitivos ou não. E por padrão esses dados
 * serão públicos, ou seja, quem tiver acesso à variável terá acesso à todos os dados
 * presentes nela;
 *      Ao declarar uma struct, pode-se apenas definir suas variáveis ou também
 * definir valores iniciais, assim como é possível definir funções.
 *      Apenas se o vetor estiver na ultima posição, ele poderá ser declarado sem
 * tamanho definido (porém desaconselho se pretende manipular memória).
 *      Como se tratam de um novo tipo, também é possível criar vetores de struct,
 * ponteiros, e funções que retornam uma struct ou recebem como parâmetro.
 * 
 *      TAMANHO:    O tamanho de uma struct varia conforme os atributos presentes.
 *                  É calculado em multilplos do maior tipo básico e da maneira na
 *                  qual os atributos estão declarados, pois isto importa na hora de
 *                  alocar memória (ver sobre packing & padding).
*/

#include <stdio.h>

// Declarando struct
struct Tipo_Aluno
{
    //Atributos
    char nome[20] = "";
    unsigned int idade = 10;
    double notas[2] = {};

    // Métodos
    double media()
    {
        double media = (notas[0] + notas[1]) / 2;
        printf("A média de %s é: %.2lf;\n", nome, media);
        return media;
    }

    void adivinharIdade(int possivelIdade)
    {
        if (possivelIdade == idade)
        {
            printf("Acertou!! A idade de %s é: %d", nome, idade);
        }
        else
        {
            printf("Errou!! A idade de %s não é: %d", nome, possivelIdade);
        }
    }
} typedef Aluno; // Com typedef agora é possível escrever Aluno ao invés de struct Tipo_Aluno;

/// Troca as notas entre dois alunos
void TrocaNotas(Aluno *aluno_1, Aluno *aluno_2)
{
    if (aluno_1 == aluno_2)
    {
        printf("Ambos os alunos são iguais!!\n");
    }
    else
    {
        double auxiliar = 0;
        for (size_t i = 0; i < 2; i++)
        {
            auxiliar = (*aluno_1).notas[i];        // Forma 1 de acessar atributo de aluno através de ponteiros
            aluno_1->notas[i] = aluno_2->notas[i]; // Forma 2 de acessar atributo de aluno através de ponteiros
            aluno_2->notas[i] = auxiliar;          // Utilizando o operador arrow
        }
    }
}

int main(void)
{
    // Instanciando struct
    Aluno newt = {"anilton Magalhaes", 19, {8.9, 9.5}},
          notw = {"outro cara", 20, {8.00, 7.5}},
          *pointerNewt = &newt,
          *pointerNotw = &notw;

    // Acessando variáveis da struct por operador ponto
    newt.media();
    notw.media();

    // Acesando structs através de ponteiros
    TrocaNotas(pointerNewt, pointerNotw);

    newt.media();
    notw.media();

    return 0;
}