// #include "konigs.h"
#include "fileHandler.h"
#include <iostream>

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;
    
    FileHandler file_handler;

    file_handler.openFile("/home/gxara/UFRJ/Teoria dos Grafos/Trabalhos/KonigsGraph/grafo.txt");

    bool matrix = true;
    std::cout << "Please choos how you want the graph to be handled" << std::endl;
    std::cout << " [1] Matrix of adjacences" << std::endl;
    std::cout << " [2] Array of adjacences" << std::endl;
    
}
