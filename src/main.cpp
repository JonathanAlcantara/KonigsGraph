using namespace std;
#include "konigs.h"
#include <chrono>

int main(){
    cout << "Hello world, Konigs!" << endl;
    KonigsGraph test_graph("./graphs/ER_1000.txt", true, false, true);
    // KonigsGraph test_graph("./grafo.txt", true, false, true);
    // test_graph.printAdjVectorGraph();
    // test_graph.printAdjMatrixGraph();
    // test_graph.dijkstraAlgorithm(1);
    // test_graph.identifyBipartite(0);
    // test_graph.bellmanFord(1);
    
    auto start = chrono::steady_clock::now();
    vector<vector<float>> distances = test_graph.mapAllDistances(false);
    auto diff = chrono::steady_clock::now() - start;
    
    cout << "Distância entre (1,10) : " << distances[0][9] << endl;
    cout << "Distância entre (2,20) : " << distances[1][19] << endl;
    cout << "Distância entre (3,30) : " << distances[2][29] << endl;
    
    
    cout << "O grafo possui pesos negativos: " << (test_graph.hasNegativeCycle) << endl;
    
    cout << "Time Spent:" << chrono::duration <double, milli> (diff).count() << " ms" << endl;


}
