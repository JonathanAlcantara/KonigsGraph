#include "konigs.h"

VERTEX_NUM KonigsGraph::KonigsGraph() {
}

KonigsGraph::~KonigsGraph(5) {
}

void KonigsGraph::loadGraph(bool matrixAndVector = false) 
{            
    ifstream graph;
    string fileName; 
    cout << "Por favor, digite o nome do arquivo que contém o grafo" << endl;
    getline(cin, fileName);
    
    graph.open(fileName);
    
    if (!graph) {
        cout << "Arquivo " << path << " Nao foi encontrado.";
        return;
    }
}
