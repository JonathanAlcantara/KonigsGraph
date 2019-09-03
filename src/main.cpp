#include "konigs.h"

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;

    KonigsGraph konigs("/home/gxara/UFRJ/Teoria dos Grafos/Trabalhos/KonigsGraph/grafo.txt");
    konigs.printStats();

    std::tuple<std::vector<unsigned>, std::vector<unsigned>> x =  konigs.DFS(2);
    
    std::vector<unsigned> dadVector =  std::get<0>(x);
    std::vector<unsigned> heightVector =  std::get<1>(x);

    for (unsigned i = 0; i <= dadVector.size() ; i++) {
        std::cout << "Altura do vértice" << i << ": " << heightVector[i] << std::endl;
        std::cout << "Pai do vértice" << i << ": " << dadVector[i] << std::endl;

    }
}
