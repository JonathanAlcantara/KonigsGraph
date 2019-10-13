using namespace std;
#include "konigs.h"
#include "edge.h"
#include <limits>
#include <queue>

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
    if (createMatrix) {
        KonigsGraph::hasAdjMatrixRepresentation = true;
    } else {
        KonigsGraph::hasAdjMatrixRepresentation = false;
    }
    if (createVector) {
        KonigsGraph::hasAdjVectorRepresentation = true;
    } else {
        KonigsGraph::hasAdjVectorRepresentation = false;
    }
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

bool KonigsGraph::allWeightsArePositive() {

    if (hasAdjMatrixRepresentation) {
        for (unsigned line = 0; line < adjMatrix.size(); line++){
            for (unsigned column = 0; column < adjMatrix.size(); column++){
                if (adjMatrix[line][column] < 0) {
                    return true;
                }
            }
        }
    } else {

        for (unsigned line = 0; line < adjVector.size(); line++){
            for (unsigned column = 0; column < adjVector[line].size(); column++){
                if(adjVector[line][column].weight < 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Method to get the neightbors of a vertex
vector<int> KonigsGraph::getAdjacences(int referenceVertex) {
    vector<int> adjacences;
    if (hasAdjVectorRepresentation) {
        for(unsigned i=0; i < adjVector[referenceVertex].size(); i ++) {
            adjacences.push_back(adjVector[referenceVertex][i].adjacentVertex)
        }
    }
    else {
        for(unsigned i=0; i < adjMatrix.size(); i ++) {
            if (adjMatrix[referenceVertex][i] > 0) {
                adjacences.push_back(i);
            }
        }
    }
    return adjacences;
}


void KonigsGraph::dijkstraAlgorithm(int startVertex) {
    if (!allWeightsArePositive) {
        cout << 'The graph has negative weights! Impossible to apply dijkstra' << endl;
        return;
    }


    struct Vertex {
        int vertexID;
        float totalCost;
        bool operator<(const Vertex& anotherVertex) const
        {
            return totalCost < anotherVertex.totalCost;
        }
    };

    vector<float> distances;
    vector<int> exploredVertexes {};
    priority_queue<Vertex> unExploredVertexes; // Priority queue to store discovered but not explored vertexes


    for (unsigned i = 0; i < adjVector.size(); i++) {
        distances[i] = numeric_limits<float>::max();
        Vertex a;
        a.vertexID = i;
        a.totalCost = numeric_limits<float>::max();
        unExploredVertexes.push(a);
    }
    distances[startVertex] = 0;

    while (unExploredVertexes.size() != 0) 
    {
        Vertex exploring = unExploredVertexes.top();
        unExploredVertexes.pop();
        exploredVertexes.push_back(exploring.vertexID);

        vector<int> adjacencesOfCurrentVertex = getAdjacences(exploring.vertexID);
                		
		for (unsigned int i = 0; i < adjacencesOfCurrentVertex.size(); i++)
		{
            int currentVertexId = exploring.vertexID;
            int adjacentVertexId = adjacencesOfCurrentVertex[i];
			float edgeWeight;
            if (hasAdjVectorRepresentation) {
                edgeWeight = adjVector[currentVertexId][adjacentVertexId].weight;
            } else {
                edgeWeight = adjMatrix[currentVertexId][adjacentVertexId];
            }


			if (distances[adjacentVertexId] > distances[currentVertexId] + edgeWeight)
			{ 
				distances[adjacentVertexId] = distances[currentVertexId] + edgeWeight;
				// unExploredVertexes[adjacentVertexId].
			}
		}
        /* 

        1. Selecionar vértice u na fila de prioridade de unexploredVertexes
        2. Adicionar u em exploredVertexes
        3. Pra cada vizinho v de u:
            3.1 Se dist[u] + w(u,v) < dist[v] #Distâcia conhecida previamente até v
                dist[v] = dist[u] + w(u,v)
         */


    }
    

}

