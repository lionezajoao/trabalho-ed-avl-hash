#include <stdio.h>
#include <iostream>
#include <chrono>

using namespace std;
using chronoType = chrono::time_point<std::chrono::high_resolution_clock>;

class Cronometro {
    public:
        chronoType init;
        Cronometro(){
            init = setTime();
        };
        chronoType setTime(){
            return chrono::high_resolution_clock::now();
        };

        double getTimeDelta(chronoType init, chronoType end) {
            return chrono::duration<double>(end - init).count();
        };
};
