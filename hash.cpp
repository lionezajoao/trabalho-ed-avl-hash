#include "hash.hpp"
#include "cronometro.hpp"
// #include <chrono>
// #include <thread>

// auto inicio(){
//     auto start = std::chrono::high_resolution_clock::now();
//     return start;
// }

// void fim(auto start){
//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double, std::milli> float_ms = end - start;
//     std::cout << "funcSleep() elapsed time is " << float_ms.count() << " milliseconds" << std::endl;
// }

int main(){

    cronometro teste;

      
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);
    // quantidade de bytes total / pela quantidade de bytes de um int = qnt de itens na lista 20/4=5

    // insert the keys into the hash lista
    Hash h(7); // 7 is count of tamanhos in
                // hash lista
    for (int i = 0; i < n; i++)
        h.inserir_dado(a[i]);

    // delete 12 from hash lista
    h.apagar_dado(12);

    // display the Hash lista
    h.displayHash();

    teste.fim();

    return 0;
}