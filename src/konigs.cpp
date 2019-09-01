#include "konigs.h"
#include <iostream>

KonigsGraph::KonigsGraph(int vertex_qty) {
    std::cout << "Please choose how you want the graph to be handled" << std::endl;
    std::cout << " [1] Matrix of adjacences" << std::endl;
    std::cout << " [2] Array of adjacences" << std::endl;    
    int answer;
    std::cin >> answer;
    if (answer == 1) {
        loadGraph(false);
    } else if (answer == 2) {
        loadGraph(true);
    } else {
        std::cout << " Invalid answer!" << std::endl;
    }

};

KonigsGraph::~KonigsGraph() {
    
};

void KonigsGraph::loadGraph(bool matrixAndVecor = false) {

};
