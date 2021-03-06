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

class KonigsGraph {
    private:
        bool isStatsUpdated;
        unsigned numberOfVertex, numberOfEdges, minDegree, maxDegree, meanDegree, medianDegree;
        std::vector<std::vector<bool>> adjMatrix;
        std::vector<std::vector<unsigned>> adjVector;
        std::vector<unsigned> maxHeightsInBFS;

    public:
        KonigsGraph(std::string file, bool createMatrix, bool createVector);
        ~KonigsGraph();
        void loadGraphFromFile(std::string file, bool createMatrix, bool createVector);
        void sortAdjVector();
        std::tuple<unsigned, unsigned, unsigned, unsigned, unsigned, unsigned> stats();
        std::tuple<std::vector<unsigned>, std::vector<unsigned>> BFS(unsigned startVertex);
        std::tuple<std::vector<unsigned>, std::vector<unsigned>> DFS(unsigned startVertex);
        unsigned distance(unsigned firstVertex, unsigned lastVertex);
        unsigned diameter(unsigned chunkIndex, unsigned chunkSize);
        std::vector<std::vector<unsigned>> connectedComponents();
        void printGraph();
        void printStats();
};
