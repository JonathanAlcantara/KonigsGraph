using namespace std;
#include "konigs.h"
#include "edge.h"

void KonigsGraph::loadGraphFromFile(string file, bool createMatrix, bool createVector) {

    isStatsUpdated = false;
    ifstream inFile;
    inFile.open(file);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
       }

    string line;
    getline(inFile, line);
    unsigned numberOfNodes = stoi(line);
    if(createMatrix){
        adjMatrix = vector<vector<float>> (numberOfNodes, vector<float>(numberOfNodes));
    }
    if(createVector){
        adjVector = vector<vector<Edge>> (numberOfNodes);
    }

    while (getline(inFile, line))
    {
        istringstream iss(line);
        unsigned vertex1, vertex2;
        float weight;

        if (!(iss >> vertex1 >> vertex2 >> weight)) { break; } // error
        if (createMatrix){
            adjMatrix[vertex1 - 1][vertex2 - 1] = weight;
            adjMatrix[vertex2 - 1][vertex1 - 1] = weight;
        }
        if (createVector){
            Edge edge1;
            Edge edge2;
            edge1.adjacentVertex =  vertex2;
            edge1.weight = weight;
            edge2.adjacentVertex =  vertex1;
            edge2.weight = weight;
            adjVector[vertex1 - 1].push_back(edge1);
            adjVector[vertex2 - 1].push_back(edge2);
        }
    }

    inFile.close();
};


KonigsGraph::KonigsGraph(string file, bool createMatrix = true, bool createVector = true){
    KonigsGraph::loadGraphFromFile(file, createMatrix, createVector);
}

KonigsGraph::~KonigsGraph(){
}

void KonigsGraph::printAdjVectorGraph(){

    for (unsigned line = 0; line < adjVector.size(); line++){
        for (unsigned column = 0; column < adjVector[line].size(); column++){
            cout << "vertex " << line + 1 << "is adjacent to " << adjVector[line][column].adjacentVertex << endl;
            // cout << adjVector[line][column].adjacentVertex << " ";
            // cout << adjVector[line][column].weight << " ";
        }
        cout << endl;
    }
}

void KonigsGraph::printAdjMatrixGraph(){

    for (unsigned line = 0; line < adjMatrix.size(); line++){
        for (unsigned column = 0; column < adjMatrix.size(); column++){
            cout << adjMatrix[line][column] << " " ;
        }
        cout << endl;
    }
}

