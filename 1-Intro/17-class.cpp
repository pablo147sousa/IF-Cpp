// Classes e Objects em C++

/**
 *      OBS:    Pesquisar Paradigma de Orientação a Objetos.
 * 
 *      CONCEITO:   No paradigma OO (Object Oriented), classes são o molde dos objetos.
 *                  Na classe é definido quais atributos os objetos possuem e quais métodos
 *                  eles podem realizar, enquanto os objetos são a instanciação da classe.
 * 
 *      CONSTRUTOR: É um método sem retorno, geralmente utilizado para inicializar os atributos do
 *                  objeto. Por padrão, caso não seja explicitamente declarado, toda classe possui
 *                  um construtor próprio que não recebe parâmetros de entrada.
 * 
 *      DESTRUTOR:  É um método sem retorno, usado para liberar o espaço de memória ocupado pelo
 *                  objeto. Por padrão, toda classe possui seu destrutor, e comumente não é necessário
 *                  que seja criado, com exceção de quando a classe utiliza alocação dinâmica, onde é
 *                  preciso desalocar seus membros antes de destruir o objeto.
 * 
 *      VISIBILIDADE:   Existem 3 tipos de visibilidades para métodos e atributos em C++:
 *                          PUBLIC:     Todos podem acessar métodos e atributos públicos.
 *                          PRIVATE:    Apenas métodos e atributos da propria classe ou
 *                                      amigos podem acessar a parte privada.
 *                          PROTECTED:  Apenas métodos e atributos da própria classe,
 *                                      subclasses ou amigos podem acessar a parte protegida
 * 
 *      FRIEND: Friend functions, são funções que possuem sua assinatura na classe precedidas de friend,
 *              são funções declaradas fora do escopo da classe que podem acessar todos os seus membros,
 *              sejam eles privados ou não.
*/

#include <stdio.h>

class Objeto
{
protected: // Somente objetos da mesma classe/subclasse podem acessar
    char nome[20] = "ubireudo";

private: // Apenas funções da própria classe podem acessar
    const char frase[13] = "Hello World!";

public: // Todos podem acessar
    /// Attribute
    int version = 0;

    /// Constructor
    Objeto(int number = 0)
    {
        version = number;
    }

    /// Destructor
    ~Objeto()
    {
        printf("%s version %d destructed\n", nome, version);
    }

    /// Method
    void HiThere()
    {
        printf("%s I'm %s, version %d\n", frase, nome, version);
    }

    // Friend Function
    friend int main(int argc, char const *argv[]);
};

int main(int argc, char const *argv[])
{
    // Declarando objeto com operador new (é preciso deletar o ponteiro manualmente após uso)
    Objeto *exemplo1 = new Objeto(1);
    exemplo1->HiThere();
    delete exemplo1;

    // Declarando objeto com construtor (é destruido automaticamente quando a função main acaba)
    Objeto exemplo2(2);
    exemplo2.HiThere();

    return 0;
}