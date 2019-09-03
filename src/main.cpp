#include "konigs.h"

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;
    KonigsGraph graph("grafo.txt");

    std::tuple<unsigned, unsigned, unsigned, unsigned, unsigned, unsigned> stats = graph.stats();

    std::cout << "Number of Vertex " << std::get<0>(stats) << std::endl;
    std::cout << "Number of Edges " << std::get<1>(stats) << std::endl;
    std::cout << "MinDegree " << std::get<2>(stats) << std::endl;
    std::cout << "MaxDegree " << std::get<3>(stats) << std::endl;
    std::cout << "MeanDegree " << std::get<4>(stats) << std::endl;
    std::cout << "MedianDegree " << std::get<5>(stats) << std::endl;

    std::tuple<std::vector<unsigned>, std::vector<unsigned>> bfsResult = graph.BFS(0);

    std::cout << "Vector of Dads: ";
    for (auto dad : std::get<0>(bfsResult)){
        std::cout << dad << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector of Heights: ";
    for (auto height : std::get<1>(bfsResult)){
        std::cout << height << " ";
    }
    std::cout << std::endl;
}
