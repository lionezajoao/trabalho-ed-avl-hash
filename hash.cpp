#include "hash.hpp"
#include "cronometro.hpp"


// função para criar e popular listas com valores de 0 a 99
auto populate(int size){
    vector<int> lista;
    srand((unsigned)time(NULL));

    for (int loop = 0; loop < size; loop++)
    {
        int valor = rand() % 100;
        lista.push_back(valor);
    }
    return lista;
}

void teste_insercao(int quantidade_de_elementos, int tamanho_hash){
    Cronometro time;

    vector<int> valores = populate(quantidade_de_elementos); // já cria o vetor dentro do teste

    // inicio do cronometro de inserção
    auto init = time.setTime();

    Hash tabela_hash(tamanho_hash);

    for (int i = 0; i < valores.size(); i++)
    {
        tabela_hash.inserir_dado(valores[i]);
    }

    // fim do cronometro de inserção
    auto end = time.setTime();
    double calc = time.getTimeDelta(init, end); // Calculando em segundos

    cout << quantidade_de_elementos << " elementos inseridos em um hash de tamanho " << tamanho_hash << " levaram " << calc << " milisegundos para serem inseridos." << endl;

    // tabela_hash.displayHash();
    
}

int main(){
    
    teste_insercao(1000,10000);
    teste_insercao(10000,100000);
    teste_insercao(100000,1000000);
    teste_insercao(1000000,10000000);
    teste_insercao(10000000,100000000);

    return 0;
}