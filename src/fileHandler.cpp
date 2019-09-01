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
    int num_vertex;
    
    while (std::getline(graphFile, row)) {
        
        
        if (row_counter == 1) {
            std::stringstream integerConversor(row);
            integerConversor >> num_vertex; 
            row_counter++;
            std::cout <<  "The graph has " << num_vertex << " vertex" << std::endl; 
            continue;
        } 

        
        std::string delimiter = " ";
        std::cout <<  "There is an edge from " << row.substr(0, row.find(delimiter))  <<  " to " << row.substr(2, row.find(delimiter)) << std::endl; 

        row_counter++;
    }


    graphFile.close();

};

void FileHandler::writeFile() {

};
