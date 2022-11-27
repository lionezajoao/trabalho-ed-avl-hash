
#include <iostream>
#include "cronometro.hpp"
#include <chrono>
#include "bst.hpp"

using namespace std;
using namespace std::chrono;


//Estrutura dos nós da árvore
class No{
public:
    int valor;
    No* esq;
    No* dir;
    int alt;
};

/*Função para criar e alocar novo nó com um valor*/
No* novoNo(int valor) {
    No* novo = new No();
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->alt = 1;
    return (novo);
}



////######FUNÇÕES AUXILIARES######
//RETORNA ALTURA DO NÓ
int altura(No * raiz){
    if (raiz == NULL)
        return 0;
    return raiz->alt;
}

//RETORNA MAIOR VALOR ENTRE DOIS INTEIROS
int max(int a, int b){
    return (a > b) ? a : b;
}

//ROTAÇÃO SIMPLES A DIREITA
No* rsd(No* y){
    No* x = y->esq;
    No* T2 = x->dir;

    //Realiza a rotação
    x->dir = y;
    y->esq = T2;

    //Atualiza as alturas
    y->alt = max(altura(y->esq),
        altura(y->dir)) + 1;
    x->alt = max(altura(x->esq),
        altura(x->dir)) + 1;

    //Retorna o novo nó
    return x;
}

//ROTAÇÃO SIMPLES A ESQUERDA
No* rse(No* x){
    No* y = x->dir;
    No* T2 = y->esq;

    //Realiza a rotação
    y->esq = x;
    x->dir = T2;

    //Atualiza as alturas
    x->alt = max(altura(x->esq),
        altura(x->dir)) + 1;
    y->alt = max(altura(y->esq),
        altura(y->dir)) + 1;

    //Retorna o novo nó
    return y;
}

//RETORNA O VALOR DO FATOR DE BALANCEAMENTO DO NÓ
int balanceamento(No* N){
    if (N == NULL)
        return 0;
    return altura(N->esq) - altura(N->dir);
}

//FUNÇÃO AUXILIAR PARA DELETAR NO
/*Dada um árvore binária de busca não vazia, retorna
o Nó com o menor valor encontrado na árvore. Note que a
busca não precisa percorrer toda a árvore.*/
No* menorValorNo(No* raiz){
    No* atual = raiz;
    /* loop down to find the esqmost leaf */
    while (atual->esq != NULL)
        atual = atual->esq;

    return atual;
}
//######FIM DAS FUNÇÕES AUXILIARES######









//FUNÇÃO DE INSERÇÃO
No* inserir(No* raiz, int valor){
    /*Caso o nó esteja vazio, faz a inserção do novo nó. */
    if (raiz == NULL)
        return(novoNo(valor));

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    else 
        return raiz;
    
    /*Atualiza a altura do nó ancestral.*/
    raiz->alt = 1 + max(altura(raiz->esq),
        altura(raiz->dir));


    /*Atribui o fator de balanceamento do Nó ancestral
    para checar se ele tornou-se desbalanceado.*/
    int balanco = balanceamento(raiz);

    // Se o Nó estiver desbalanceado, existem 4 casos:

    // Rotação Simples a Direita
    if (balanco > 1 && valor < raiz->esq->valor)
        return rsd(raiz);

    // Rotação Simples a Esquerda
    if (balanco < -1 && valor > raiz->dir->valor)
        return rse(raiz);

    // Rotação Dupla a Direita
    if (balanco > 1 && valor > raiz->esq->valor){
        raiz->esq = rse(raiz->esq);
        return rsd(raiz);
    }

    // Rotação Dupla a Esquerda
    if (balanco < -1 && valor < raiz->dir->valor){
        raiz->dir = rsd(raiz->dir);
        return rse(raiz);
    }

    return raiz;
}

//FUNÇÃO DE REMOÇÃO
/*Função recursiva para excluir um Não com determinado 
valor da subárvore com determinada raiz. Retorna a raiz 
da subárvore modificada.*/
No* deleteNo(No* raiz, int valor){
    
  
    if (raiz == NULL)
        return raiz;

    /*Se o valor a ser excluído for menor que o valor da raiz, 
    ele estará na subárvore esq*/
    if (valor < raiz->valor)
        raiz->esq = deleteNo(raiz->esq, valor);

    /*Se o valor a ser excluído for maior que o valor da raiz, 
    ele estará na subárvore dir*/
    else if (valor > raiz->valor)
        raiz->dir = deleteNo(raiz->dir, valor);

    /*se o valor for igual ao valor da raiz, 
    então este é o não a ser excluído*/
    else
    {
        // Não com apenas um filho ou sem filho 
        if ((raiz->esq == NULL) ||
            (raiz->dir == NULL))
        {
            No* temp = raiz->esq ? raiz->esq : raiz->dir;

            // Caso de Nó sem filho 
            if (temp == NULL)
            {
                temp = raiz;
                raiz = NULL;
            }
            else // caso de nó com um filho
                *raiz = *temp; // Copie o conteúdo do filho não vazio
            free(temp);
        }
        else
        {
            /*Não com dois filhos: Obtenha o sucessor 
            inorder (menor na subárvore dir)*/
            No* temp = menorValorNo(raiz->dir);

            /*Copie os dados do sucessor do pedido para este nó*/
            raiz->valor = temp->valor;

            // Excluir o sucessor inorder
            raiz->dir = deleteNo(raiz->dir,
                temp->valor);
        }
    }

    /*Se a árvore tiver apenas um Nó, ela retorna*/
    if (raiz == NULL)
        return raiz;

    //Atualiza a altura do Nó corrente
    raiz->alt = 1 + max(altura(raiz->esq),
        altura(raiz->dir));

    //Obtém fator de equilíbrio
    int balanco = balanceamento(raiz);

    /*Se este Não ficar desequilibrado, então há 4 casos*/

    // rotação simples a direita 
    if (balanco > 1 &&
        balanceamento(raiz->esq) >= 0)
        return rsd(raiz);
    
    //rotação dupla a direita
    if (balanco > 1 &&
        balanceamento(raiz->esq) < 0)
    {
        raiz->esq = rse(raiz->esq);
        return rsd(raiz);
    }

    //rotação simples a esquerda 
    if (balanco < -1 &&
        balanceamento(raiz->dir) <= 0)
        return rse(raiz);

    //rotação dupla a esquerda
    if (balanco < -1 &&
        balanceamento(raiz->dir) > 0)
    {
        raiz->dir = rsd(raiz->dir);
        return rse(raiz);
    }

    return raiz;
}

//FUNÇÃO DE PERCURSO PRÉ-ORDEM
void preOrderAvl(No* root) {

    if (root != NULL) {
        root->valor;
        preOrderAvl(root->esq);
        preOrderAvl(root->dir);
    }
    
}


/*
int main() {

    No* arv = NULL; //criação da árvore
    
    



























    /*
    int N = 4000;


    for (int i = 1; i < N; i++) {
        arv = insereBst(arv, i);
    }

    auto start = steady_clock::now();
    preOrder(arv);
    auto end = steady_clock::now();
    auto elapsed = end - start;

    std::cout << "\n\n\n";

    std::cout << elapsed.count() << "ns\n";

    /*
    No* arv = NULL; //criação da árvore
    int N = 100;


    for (int i = 1; i < N; i++) {
        arv = inserir(arv, i);
    }

    auto start = steady_clock::now();
    
    for (int i = 1; i < N; i++) {
        arv = deleteNo(arv, i);
    }

    auto end = steady_clock::now();

    auto elapsed = end - start;
    std::cout << elapsed.count() << "ns\n";

    std::cout << "\n";

    preOrderAvl(arv);
    */



    /*
    No* arv = NULL; //criação da árvore
    bst* root = NULL;
    int N = 4020;

    auto start = steady_clock::now();
    
    for (int i = 1; i < N; i++) {
        root = insereBst(root, i);
    }
   
    auto end = steady_clock::now();

    auto elapsed = end - start;
    std::cout << elapsed.count() << "ns\n";
    */
    

    /*
    int N = 1; //número de nós a serem criados

    //insere um nó na árvore
    for (int i = 1; i <= N; i++) {
        arv = inserir(arv, i);
    }
    
    //inicio da contagem do tempo
    auto start = steady_clock::now(); 
 



    //término da contagem do tempo
    auto end = steady_clock::now();

    //diminui tempo final pelo inicial
    auto elapsed = end - start;
    */
    //imprime o tempo para criação da árvore com N nós.
    //(tempo em nanosegundos.
    //std::cout << elapsed.count() << "ns\n";
}
