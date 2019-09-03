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
    unsigned numberOfNodes = std::stoi(line);
    if(createMatrix){
        adjMatrix = std::vector<std::vector<bool>> (numberOfNodes, std::vector<bool>(numberOfNodes));
    }
    if(createVector){
        adjVector = std::vector<std::vector<unsigned>> (numberOfNodes);
    }

    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        unsigned vertex1, vertex2;

        if (!(iss >> vertex1 >> vertex2)) { break; } // error
        if (createMatrix){
            adjMatrix[vertex1 - 1][vertex2 - 1] = true;
            adjMatrix[vertex2 - 1][vertex1 - 1] = true;
        }
        if (createVector){
            adjVector[vertex1 - 1].push_back(vertex2 - 1);
            adjVector[vertex2 - 1].push_back(vertex1 - 1);
        }
    } 

    inFile.close();
};

std::tuple<unsigned, unsigned, unsigned, unsigned, unsigned, unsigned> 
KonigsGraph::stats(){

    if (!isStatsUpdated){
        numberOfVertex = adjVector.size();
        std::vector<unsigned> tempDegrees(numberOfVertex);
        unsigned currentDegree, sumOfDegrees = 0;
        minDegree = maxDegree = adjVector[0].size();
        for (unsigned i = 0; i < numberOfVertex; i++){
            currentDegree = adjVector[i].size();
            sumOfDegrees += currentDegree;
            tempDegrees[i] = currentDegree;
            minDegree = std::min<unsigned>(currentDegree, minDegree);
            maxDegree = std::max<unsigned>(currentDegree, minDegree);
        }
        std::sort(tempDegrees.begin(), tempDegrees.end());
        medianDegree = numberOfVertex % 2 == 0 ? tempDegrees[int(numberOfVertex/2) + 1] : (tempDegrees[numberOfVertex/2 - 1] + tempDegrees[numberOfVertex/2])/2;
        medianDegree = tempDegrees[numberOfVertex/2];
        meanDegree = sumOfDegrees/numberOfVertex;
        numberOfEdges = sumOfDegrees/2;
        isStatsUpdated = true;
    }
    return std::make_tuple(numberOfVertex, numberOfEdges, minDegree, maxDegree, meanDegree, medianDegree);
}

std::tuple<std::vector<unsigned>, std::vector<unsigned>>
KonigsGraph::BFS(unsigned startVertex){
    std::vector<unsigned> dadVector (numberOfVertex, 0);
    std::vector<unsigned> heightVector (numberOfVertex, -1);
    std::queue<unsigned> discoveredQueue;

    heightVector[startVertex] = 0;
    discoveredQueue.push(startVertex);

    while (!discoveredQueue.empty()){
        unsigned currentVertex = discoveredQueue.front();
        discoveredQueue.pop();
        unsigned heightOfCurrVertex = heightVector[currentVertex];
        for (auto neighbor: adjVector[currentVertex]){
            if (heightVector[neighbor] == -1) {
                heightVector[neighbor] = heightOfCurrVertex + 1;
                dadVector[neighbor] = currentVertex + 1;
                discoveredQueue.push(neighbor);
            }
        }
    }

    return std::make_tuple(dadVector, heightVector);
}

std::tuple<std::vector<unsigned>, std::vector<unsigned>>
KonigsGraph::DFS(unsigned startVertex){
    std::vector<unsigned> dadVector (numberOfVertex, 0);
    std::vector<unsigned> heightVector (numberOfVertex, -1);
    std::stack<unsigned> toExploreStack;

    heightVector[startVertex] = 0;
    for (auto neighbor: adjVector[startVertex]) {
            toExploreStack.push(neighbor);
            dadVector[neighbor] = startVertex + 1;
    }

    while (!toExploreStack.empty()){

        unsigned currentVertex = toExploreStack.top();
        toExploreStack.pop();

        if(heightVector[currentVertex] == -1){
            unsigned heightOfCurrVertex = heightVector[dadVector[currentVertex] - 1] + 1;
            heightVector[currentVertex] = heightOfCurrVertex;
            for (auto neighbor: adjVector[currentVertex]) {
                toExploreStack.push(neighbor);
                if (heightVector[neighbor] == -1){
                    dadVector[neighbor] = currentVertex + 1;
                }
            }
        }
    }
    return std::make_tuple(dadVector, heightVector);
}

unsigned KonigsGraph::distance(unsigned firstVertex, unsigned lastVertex){
    return std::get<1>(KonigsGraph::BFS(firstVertex))[lastVertex];
}

unsigned KonigsGraph::diameter(){
    unsigned currentMaxDistance = 0;
    for (unsigned i = 0; i <= numberOfVertex/2; i++){
    }
    return 0;
}

KonigsGraph::KonigsGraph(std::string file){
    KonigsGraph::loadGraphFromFile(file, true, true);
    KonigsGraph::stats();
}

void KonigsGraph::printStats(){
    std::tuple<unsigned, unsigned, unsigned, unsigned, unsigned, unsigned> stats = KonigsGraph::stats();
    std::cout << "Number of vertex: " << std::get<0>(stats) << std::endl;
    std::cout << "Number of edges: " << std::get<1>(stats) << std::endl;
    std::cout << "Minimum degree: " << std::get<2>(stats) << std::endl;
    std::cout << "Maximum degree: " << std::get<3>(stats) << std::endl;
    std::cout << "Mean degree: " << std::get<4>(stats) << std::endl;
    std::cout << "Median degree: " << std::get<5>(stats) << std::endl;
};
