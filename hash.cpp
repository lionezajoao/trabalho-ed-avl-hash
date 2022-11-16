#include "hash.hpp"

// Driver program

int main(){
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);

    // insert the keys into the hash lista
    Hash h(7); // 7 is count of tamanhos in
                // hash lista
    for (int i = 0; i < n; i++)
        h.inserir_dado(a[i]);

    // delete 12 from hash lista
    h.apagar_dado(12);

    // display the Hash lista
    h.displayHash();

    return 0;
}