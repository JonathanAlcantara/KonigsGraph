#include "konigs.h"

void KonigsGraph::loadGraphFromFile(std::string file, bool createMatrix = true, bool createVector = true) {

    isStatsUpdated = false;
    std::ifstream inFile;
    inFile.open(file);
    if (!inFile) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
       }

    std::string line;
    std::getline(inFile, line);
    unsigned numOfLines = std::stoi(line);
    unsigned numberOfNodes;
    for (unsigned i = 0; i < numOfLines; i++){
        std::getline(inFile, line);
        std::istringstream iss(line);
        unsigned a, b;
        if (!(iss >> a >> b)) { break; } // error
        numberOfNodes = std::max(std::max(numberOfNodes, b), a);
    }
    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    if(createMatrix){
        //std::vector<std::vector<bool>> tempMatrix (numberOfNodes, std::vector<bool>(numberOfNodes));
        adjMatrix = std::vector<std::vector<bool>> (numberOfNodes, std::vector<bool>(numberOfNodes));
    }
    if(createVector){
        adjVector = std::vector<std::vector<unsigned>> (numberOfNodes);
    }

    std::getline(inFile, line);
    for (unsigned i = 0; i < numOfLines; i++){
        std::getline(inFile, line);
        std::istringstream iss(line);
        unsigned vertex1, vertex2;
        if (!(iss >> vertex1 >> vertex2)) { break; } // error
        if (createMatrix) adjMatrix[vertex1][vertex2] = true;
        if (createVector) adjVector[vertex1].push_back(vertex2);
    } 
    inFile.close();
};

std::tuple<unsigned, unsigned, unsigned, unsigned, unsigned, unsigned> 
KonigsGraph::stats(){

    if (!isStatsUpdated){
        numberOfVertex = adjVector.size();
        std::vector<unsigned> tempDegrees(numberOfVertex);
        unsigned currentDegree, sumOfDegrees = 0;
        minDegree = maxDegree = 0;
        for (unsigned i = 0; i < numberOfVertex; i++){
            currentDegree = adjVector[i].size();
            sumOfDegrees += currentDegree;
            tempDegrees[i] = currentDegree;
            minDegree = std::min<unsigned>(currentDegree, minDegree);
            maxDegree = std::max<unsigned>(currentDegree, minDegree);
        }
        medianDegree = tempDegrees[numberOfVertex/2];
        meanDegree = sumOfDegrees/numberOfVertex;
        numberOfEdges = sumOfDegrees/2;
        isStatsUpdated = true;
    }
    return std::make_tuple(numberOfVertex, numberOfEdges, minDegree, maxDegree, meanDegree, medianDegree);
}

KonigsGraph::KonigsGraph(std::string file){
    KonigsGraph::loadGraphFromFile(file);
    KonigsGraph::stats();
}
