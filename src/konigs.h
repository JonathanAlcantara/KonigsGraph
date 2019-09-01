#include <iostream>
#include <array>
#include <vector>
#include <bitset>

template <std::size_t VERTEX_NUM>
class KonigsGraph{
    private: 
        std::array<std::bitset<VERTEX_NUM>, VERTEX_NUM> adjMatrix;
        std::array<std::vector<int>, VERTEX_NUM> adjVector;
    public: 
        void loadGraph(bool matrixAndVector);
        int* stats();
        void BFS(int startVertex);
        void DFS(int startVertex);
        int* distance(int firstVertex, int lastVertex);
        int diameter();
        int* connectedComponents();
        void printGraph();
};


