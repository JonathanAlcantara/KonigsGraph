// #include "konigs.h"
#include "fileHandler.h"
#include <iostream>

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;
    
    FileHandler file_handler;

    file_handler.openFile("/home/gxara/UFRJ/Teoria dos Grafos/Trabalhos/KonigsGraph/grafo.txt");
    
    // KonigsGraph::konigs();
}
