#include <iostream>
#include <array>
#include <vector>
#include <bitset>

// template <std::size_t VERTEX_NUM>
class KonigsGraph {
    private:
        int VERTEX_NUM;
        // int [VERTEX_NUM][VERTEX_NUM]  adjMatrix;
        // int, 3> adjVector;
    public:
        KonigsGraph(int vertex_qty);
        ~KonigsGraph();
        void loadGraph(bool matrixAndVector);
        int* stats();
        void BFS(int startVertex);
        void DFS(int startVertex);
        int* distance(int firstVertex, int lastVertex);
        int diameter();
        int* connectedComponents();
        void printGraph();
};
