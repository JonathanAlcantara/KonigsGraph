using namespace std;
#include "konigs.h"
#include "edge.h"
#include "vertex.h"
#include <limits>
#include <queue>
#include <climits>

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
    numberOfNodes = stoi(line);
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
        if (createMatrix && !isDirected){
            adjMatrix[vertex1 - 1][vertex2 - 1] = weight;
            adjMatrix[vertex2 - 1][vertex1 - 1] = weight;
        } else if (createMatrix && isDirected) {
            adjMatrix[vertex1 - 1][vertex2 - 1] = weight;
        }
        if (createVector && !isDirected){
            Edge edge1;
            Edge edge2;
            edge1.adjacentVertex =  vertex2-1;
            edge1.weight = weight;
            edge2.adjacentVertex =  vertex1-1;
            edge2.weight = weight;
            adjVector[vertex1 - 1].push_back(edge1);
            adjVector[vertex2 - 1].push_back(edge2);
        } else if (createVector && isDirected){
            Edge edge1;
            edge1.adjacentVertex =  vertex2-1;
            edge1.weight = weight;
            adjVector[vertex1 - 1].push_back(edge1);

        }
    }

    inFile.close();
};

KonigsGraph::KonigsGraph(string file, bool createMatrix = true, bool createVector = true, bool directed = false){
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
    if (directed) {
        KonigsGraph::isDirected = true;
    } else {
        KonigsGraph::isDirected = false;
    }
    KonigsGraph::loadGraphFromFile(file, createMatrix, createVector);
}

KonigsGraph::~KonigsGraph(){
}

void KonigsGraph::printAdjVectorGraph(){

    for (unsigned line = 0; line < adjVector.size(); line++){
        for (unsigned column = 0; column < adjVector[line].size(); column++){
            cout << "vertex " << line + 1 << "is adjacent to " << adjVector[line][column].adjacentVertex << endl;
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
                    return false;
                }
            }
        }
    } else {

        for (unsigned line = 0; line < adjVector.size(); line++){
            for (unsigned column = 0; column < adjVector[line].size(); column++){
                if(adjVector[line][column].weight < 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> KonigsGraph::getAdjacences(int referenceVertex) {
    vector<int> adjacences;
    if (hasAdjVectorRepresentation) {
        for(unsigned i=0; i < adjVector[referenceVertex].size(); i ++) {
            adjacences.push_back(adjVector[referenceVertex][i].adjacentVertex);
            cout << adjVector[referenceVertex][i].adjacentVertex << endl;
        }
    }
    else {
        for(unsigned i=0; i < adjMatrix.size(); i ++) {
            // cout << adjMatrix[referenceVertex][i] << endl;
            if (adjMatrix[referenceVertex][i] > 0) {
                adjacences.push_back(i);
            }
        }
    }

    return adjacences;
}

void KonigsGraph::dijkstraAlgorithm(int startVertex) {
    if (!allWeightsArePositive()) {
        cout << "The graph has negative weights! Impossible to apply dijkstra" << endl;
        return;
    }

    startVertex = startVertex -1 ;
    vector<bool> exploredVertexes (adjMatrix.size(), false);
    vector<float> distances (adjMatrix.size());

    priority_queue<Vertex> unExploredVertexes; // Priority queue to store discovered but not explored vertexes

    if(hasAdjVectorRepresentation) {
        for (unsigned i = 0; i < adjVector.size() ; i++) {
            distances[i] = numeric_limits<float>::max();
        }
    } else {
    
        for (unsigned i = 0; i < adjMatrix.size(); i++) {
            distances[i] = numeric_limits<float>::max();
        }
    }

    distances[startVertex] = 0;
    
    Vertex a;
    a.vertexID = startVertex;
    a.totalCost = 0;
    
    unExploredVertexes.push(a);

    while (unExploredVertexes.size() != 0) 
    {
        Vertex exploring = unExploredVertexes.top();
        unExploredVertexes.pop();
        exploredVertexes[exploring.vertexID] = true;
        vector<int> adjacencesOfCurrentVertex = getAdjacences(exploring.vertexID);
		for (unsigned int i = 0; i < adjacencesOfCurrentVertex.size(); i++)
		{
            int currentVertexId = exploring.vertexID ;
            int adjacentVertexId = adjacencesOfCurrentVertex[i]  ;
            
            if (exploredVertexes[adjacentVertexId]) {
                continue;
            }

			float edgeWeight;
            if (hasAdjVectorRepresentation) {
                edgeWeight = adjVector[currentVertexId][adjacentVertexId].weight;
            } else {
                edgeWeight = adjMatrix[currentVertexId][adjacentVertexId];
            }

			if (distances[adjacentVertexId] > distances[currentVertexId] + edgeWeight)
			{
				distances[adjacentVertexId] = distances[currentVertexId] + edgeWeight;

                Vertex b;
                b.vertexID = adjacentVertexId;
                b.totalCost = distances[currentVertexId] + edgeWeight;

                unExploredVertexes.push(b);
			}
		}
    }

    if(hasAdjVectorRepresentation) {
        for (unsigned i = 0; i < adjVector.size() ; i++) {
            // distances[i] = numeric_limits<float>::max();
            cout << "distance from vertex " << startVertex << " and " << i << " = " << distances[i] << endl;
        }
    } else {
        for (unsigned i = 0; i < adjMatrix.size(); i++) {
            // distances[i] = numeric_limits<float>::max();
            cout << "distance from vertex " << startVertex << " and " << i << " = " << distances[i] << endl;
        }
    }

}

bool KonigsGraph::identifyBipartite(int initial_vertex = 0) {
    /*
    Adaptation of the BFS algorithm that enables to identify if a graph is bipartite.
    The method separates all vertexes into 2 groups. If one vertex belongs to both groupos this means
    that the graph is not bipartite
    */
    if (hasAdjMatrixRepresentation) {
        queue <int> to_explore; 
        vector<short int> explored(numberOfNodes, 0); // 0 for unexplored, 1 for group 1, 2 for group 2
        to_explore.push(initial_vertex);
        explored[initial_vertex] = 1;
        while (to_explore.size() > 0) {
            int u = to_explore.front();
            to_explore.pop();
            for (int v = 0; v < numberOfNodes ; v++) {
                if (adjMatrix[u][v] != 0) {
                    if (explored[v] == 0) {
                        to_explore.push(v);
                        if (explored[u] == 1)
                            explored[v] = 2;
                        else if (explored[u] == 2)
                            explored[v] = 1;
                    }
                    else if (explored[v] == explored[u]) {
                        cout << "Não é bipartido" << endl;
                        return false;
                    }
                    else if (explored[v] != explored[u]) {
                        continue;
                    }
                }
            }
        }
        cout << "É bipartido" <<endl;
        KonigsGraph::buildBipartite(explored);
        return true;
        // Must build the bipartition representation

    }
}

void KonigsGraph::buildBipartite(vector<short int> explored_nodes) {
    pair < list <int>, list <int> > groups;
    int group_number;
    for (int v = 0; v < explored_nodes.size() ; v++) {
        group_number = explored_nodes[v];
        if (group_number == 1) {
            groups.first.push_back(v);
        } else if (group_number == 2)
            groups.second.push_back(v);
    }
}

vector<float> KonigsGraph::bellmanFord(int start_node) {
    start_node = start_node - 1;
    vector<vector<float>> distances (numberOfNodes, vector<float>(numberOfNodes, INT_MAX));
    distances[0][start_node] = 0;

    for (int i = 1; i < numberOfNodes; i ++) {
        for (int v = 0; v < numberOfNodes; v ++) {
            distances[i][v] = distances[i-1][v];
            for (int w = 0; w < numberOfNodes; w++) {
                if (adjMatrix[w][v] != 0) {  // This means that there is an edge
                    if (distances[i-1][w] + adjMatrix[w][v] < distances[i][v]) {
                        distances[i][v] = distances[i-1][w] + adjMatrix[w][v];
                    }
                }
            }
        }
    }
    
    KonigsGraph::checkForNegativeCycle(distances[numberOfNodes - 1]);
    // KonigsGraph::printDistancesMatrix(distances);

    return distances[numberOfNodes -1];
}


vector<vector<float>> KonigsGraph::mapAllDistances(bool print = false) {
    vector<vector<float>> distancesMatrix (numberOfNodes, vector<float>(numberOfNodes, INT_MAX));
    
    for (int i = 1; i <= numberOfNodes; i ++) {
        distancesMatrix[i-1] = KonigsGraph::bellmanFord(i);
    }

    if (print) {
        KonigsGraph::printDistancesMatrix(distancesMatrix);
    }

    return distancesMatrix;
}

void KonigsGraph::checkForNegativeCycle(vector<float> distances) {
    for (int u = 0; u < numberOfNodes; u ++) {
        for (int v = 0; v < numberOfNodes; v ++) {
            if (adjMatrix[u][v] != 0) {
                if (distances[u] + adjMatrix[u][v] < distances[v]) {
                    hasNegativeCycle = true;
                }
            }
        }
    }
}

void KonigsGraph::printDistancesMatrix(vector<vector<float>> distances) {

    for (unsigned line = 0; line < distances.size(); line++){
        for (unsigned column = 0; column < distances.size(); column++){
            if (distances[line][column] == INT_MAX) {
                cout << "inf" << " " ;
            } else if (distances[line][column] == - INT_MAX) {
                cout << "- inf" << " " ;
            } else {
                cout << distances[line][column] << " " ;
            }
        }
        cout << endl;
    }
}
