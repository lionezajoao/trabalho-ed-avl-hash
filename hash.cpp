#include "hash.hpp"
// #include "cronometro.hpp"


// função para criar e popular listas com valores de 0 a 99
auto populate(int size){
    vector<int> lista;
    for (int loop = 0; loop < size; loop++)
    {
        int valor = rand() % 100;
        lista.push_back(valor);
    }
    return lista;
}

void teste_insercao(int quantidade_de_elementos, int tamanho_hash){

    vector valores = populate(quantidade_de_elementos); // já cria o vetor dentro do teste

    // inicio do cronometro de inserção

    Hash tabela_hash(tamanho_hash);

    for (int i = 0; i < valores.size(); i++)
    {
        tabela_hash.inserir_dado(valores[i]);
    }
    // fim do cronometro de inserção

    tabela_hash.displayHash();
    
}

int main(){

    teste_insercao(20,30);

    return 0;
}