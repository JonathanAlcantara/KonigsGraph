using namespace std;
#include "konigs.h"
#include <chrono>

int main(){
    cout << "Hello world, Konigs!" << endl;
    cout << "Starting AS Graph" << endl;
    // KonigsGraph test_graph("./graphs/ER_50.txt", true, false, true);
    KonigsGraph test_graph("./grafo.txt", true, false, true);
    // test_graph.printAdjVectorGraph();
    // test_graph.printAdjMatrixGraph();
    // test_graph.dijkstraAlgorithm(1);
    // test_graph.identifyBipartite(0);
    test_graph.bellmanFord(1);
    test_graph.~KonigsGraph();   

    // cout << "Starting Rede Colaboraçao Graph" << endl;
    // KonigsGraph colaboration_graph("./rede_colaboracao.txt", true, false);
    // colaboration_graph.printAdjVectorGraph();
    // colaboration_graph.printAdjMatrixGraph();
    // colaboration_graph.dijkstraAlgorithm(1);
    // colaboration_graph.~KonigsGraph();   

}
