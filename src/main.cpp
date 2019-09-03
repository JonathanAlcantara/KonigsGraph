#include "konigs.h"

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;

    KonigsGraph konigs("/home/gxara/UFRJ/Teoria dos Grafos/Trabalhos/KonigsGraph/grafo.txt");
    konigs.printStats();
}
