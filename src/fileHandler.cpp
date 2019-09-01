#include "fileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream> 

FileHandler::FileHandler() {

};

FileHandler::~FileHandler() {
    
};

void FileHandler::openFile(std::string filePath) {
    std::ifstream graphFile;
    int sum = 0;
    int x;    
    
    graphFile.open(filePath);
    if (!graphFile) {
        std::cout << "Could not open the graph\n";
        return;
    }
    std::cout << "Graph found!\n";

    std::string row;

    int row_counter = 1;

    
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

        row_counter++;
    }

    graphFile.close();

};

int FileHandler::get_vertex_qty() {
    return vertex_qty;
};


void FileHandler::writeFile() {

};
