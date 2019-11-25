using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <fstream>
#include <tuple>
#include <sstream>
#include <string>
#include "edge.h"

class KonigsGraph {
    private:
        bool isDirected;
        bool isStatsUpdated;
        bool hasAdjVectorRepresentation;
        bool hasAdjMatrixRepresentation;
        unsigned numberOfNodes, numberOfEdges, minDegree, maxDegree, meanDegree, medianDegree;
        vector<vector<float>> adjMatrix;
        vector<vector<Edge>> adjVector;

    public:
        KonigsGraph(string file, bool createMatrix, bool createVector, bool directed);
        ~KonigsGraph();
        void loadGraphFromFile(string file, bool createMatrix, bool createVector);
        void printAdjVectorGraph();
        void printAdjMatrixGraph();
        bool allWeightsArePositive();
        void dijkstraAlgorithm(int startVertex);
        vector<int> getAdjacences(int referenceVertex);
        bool identifyBipartite(int);
        void buildBipartite(vector<short int> explored_nodes);
        vector<float> bellmanFord(int start_node);
        vector<vector<float>> mapAllDistances(bool print);
        void checkForNegativeCycle(vector<float> distances);
        void printDistancesMatrix(vector<vector<float>>);
        bool hasNegativeCycle = false;
};
