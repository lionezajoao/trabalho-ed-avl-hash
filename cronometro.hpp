#include <stdio.h>

template <typename T>
class cronometro
{
public:
    auto inicio;
    auto fim;
    cronometro(){
        inicio = std::chrono::high_resolution_clock::now();
    }
    void fim(){
        fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> float_ms = fim - inicio;
        std::cout << "Essa função durou " << float_ms.count() << " milisegundos." << std::endl;
    }
};
