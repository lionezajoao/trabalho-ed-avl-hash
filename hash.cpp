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

void teste_insercao_busca(int quantidade_de_elementos, int tamanho_hash){

    cout << quantidade_de_elementos << " elementos e hash de tamanho " << tamanho_hash << endl; 
    Cronometro time;

    vector<int> valores = populate(quantidade_de_elementos); // já cria o vetor dentro do teste
    Hash tabela_hash(tamanho_hash);

    //  Cálculo de inserção de valores na hash
    auto inicioInsercao = time.setTime();


    for (int i = 0; i < valores.size(); i++)
    {
        tabela_hash.inserir_dado(valores[i]);
    }
    auto fimInsercao = time.setTime();
    double tempoInsercao = time.getTimeDelta(inicioInsercao, fimInsercao); // Calculando em milisegundos

    cout << "Tempo de inserção de todos os valores na hash: " << tempoInsercao << endl;

    auto menorTempoRemocao = 0.0;
    auto maiorTempoRemocao = 0.0;
    double tempoMedioRemocao = 0.0;
    int tamVetor = valores.size();

    // Cálculo de busca e remoção de valores da hash
    for (int i=0; i < tamVetor; i++) {
        auto inicioRemocao = time.setTime();
        tabela_hash.apagar_dado(valores[i]);
        auto fimRemocao = time.setTime();

        double tempoRemocao = time.getTimeDelta(inicioRemocao, fimRemocao);

        if (menorTempoRemocao == 0) {
            menorTempoRemocao = tempoRemocao;
        }

        if (tempoRemocao > maiorTempoRemocao) {
            maiorTempoRemocao = tempoRemocao;
        } else if ( tempoRemocao < menorTempoRemocao) {
            menorTempoRemocao = tempoRemocao;
        }

        tempoMedioRemocao += tempoRemocao;
    }

    tempoMedioRemocao = tempoMedioRemocao/tamVetor;

    cout << "Menor tempo de remoção da hash: " << menorTempoRemocao << endl;
    cout << "Maior tempo de remoção da hash: " << maiorTempoRemocao << endl;
    cout << "Tempo médio de remoção da hash: " << tempoMedioRemocao  << endl;
    cout << '\a' << endl;
    
}

int main(int argc, char *argv[]){

    int elem = atoi(argv[1]);
    int hash_size = elem*10;

    teste_insercao_busca(elem, hash_size);

    // double total = 0.0;
    // for (int i=0; i<5; i++) {
    //     total += teste_insercao(elem, hash_size);
    // }
    
    // cout << response << endl;

    return 0;
}