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

double teste_insercao(int quantidade_de_elementos, int tamanho_hash){
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

    // cout << quantidade_de_elementos << " elementos inseridos em um hash de tamanho " << tamanho_hash << " levaram " << calc << " milisegundos para serem inseridos." << endl;
    // tabela_hash.displayHash();
    return calc;
    
}

int main(int argc, char *argv[]){

    int elem = atoi(argv[1]);
    int hash_size = elem*10;

    double total = 0.0;
    for (int i=0; i<5; i++) {
        total += teste_insercao(elem, hash_size);
    }
    
    cout << total/5.0 << endl;

    return 0;
}