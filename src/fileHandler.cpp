#include "fileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream> 

FileHandler::FileHandler() {
    edges_qty = 0;
};

FileHandler::~FileHandler() {
    
};

void FileHandler::openFile(std::string filePath) {
    filePath = filePath;
    std::ifstream graphFile;
    int x;    
    
    graphFile.open(filePath);
    if (!graphFile) {
        std::cout << "Could not open the graph\n";
        return;
    }
    std::cout << "Graph found!\n";

    std::string row;

    int row_counter = 1;

    // Iterates over rows to get vertex qty and edges qty
    while (std::getline(graphFile, row)) {
        
        if (row_counter == 1) {
            std::stringstream integerConversor(row);
            integerConversor >> vertex_qty; 
            row_counter++;
            std::cout <<  "The graph has " << vertex_qty << " vertex" << std::endl; 
            continue;
        } 

        
        std::string delimiter = " ";
        std::cout <<  "There is an edge from " << row.substr(0, row.find(delimiter))  <<  
        " to " << row.substr(2, row.find(delimiter))  << std::endl;
        edges_qty ++;
        row_counter++;
    }
    
    graphFile.close();

    graphFile.open(filePath);
    if (!graphFile) {
        std::cout << "Could not open the graph\n";
        return;
    }

    // Iterates again over rows to get edges
    row_counter = 1;

    edges = new int*[edges_qty];
    for(int i = 0; i < edges_qty; i++) {
        edges[i] = new int[2]; 
    }

    while (std::getline(graphFile, row)) {
        
        if (row_counter == 1) {
            row_counter++;
            continue;
        }

        std::string delimiter = " ";
        std::cout <<  "There is an edge from " << row.substr(0, row.find(delimiter))  <<  
        " to " << row.substr(2, row.find(delimiter))  << std::endl; 

        std::stringstream integerConversor(row.substr(0, row.find(delimiter)));
        integerConversor >> edges[row_counter-2][0]; 
        std::stringstream integerConversor2(row.substr(2, row.find(delimiter)));
        integerConversor >> edges[row_counter-2][1]; 
        
        row_counter++;
    }

    graphFile.close();

};


int FileHandler::get_vertex_qty() {
    return vertex_qty;
};


int** FileHandler::get_edges() {
    return edges;
}
