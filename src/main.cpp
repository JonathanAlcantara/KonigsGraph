#include "konigs.h"
#include <chrono>

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;

    std::cout << "Starting AS Graph" << std::endl;
    KonigsGraph test_graph("./grafo.txt", true, true);
    test_graph.printAdjVectorGraph();
    test_graph.printAdjMatrixGraph();
    test_graph.~KonigsGraph();   

}
