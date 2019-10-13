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
        bool isStatsUpdated;
        unsigned numberOfVertex, numberOfEdges, minDegree, maxDegree, meanDegree, medianDegree;
        vector<vector<float>> adjMatrix;
        vector<vector<Edge>> adjVector;

    public:
        KonigsGraph(string file, bool createMatrix, bool createVector);
        ~KonigsGraph();
        void loadGraphFromFile(string file, bool createMatrix, bool createVector);
        void printAdjVectorGraph();
        void printAdjMatrixGraph();
        // void printStats();
};
