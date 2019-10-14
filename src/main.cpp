#include "konigs.h"
#include <chrono>

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;

    std::cout << "Starting AS Graph" << std::endl;
    KonigsGraph test_graph("./grafo.txt", true, false);
    test_graph.printAdjVectorGraph();
    test_graph.printAdjMatrixGraph();
    test_graph.dijkstraAlgorithm(1);
    test_graph.~KonigsGraph();   

    std::cout << "Starting Rede Colaboraçao Graph" << std::endl;
    KonigsGraph colaboration_graph("./rede_colaboracao.txt", true, false);
    colaboration_graph.printAdjVectorGraph();
    colaboration_graph.printAdjMatrixGraph();
    colaboration_graph.dijkstraAlgorithm(1);
    colaboration_graph.~KonigsGraph();   

}
