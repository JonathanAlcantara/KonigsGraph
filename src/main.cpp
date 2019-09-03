#include "konigs.h"

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;
    KonigsGraph graph("grafo.txt");

    graph.printStats();

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


    std::tuple<std::vector<unsigned>, std::vector<unsigned>> dfsResult = graph.DFS(3);

    std::cout << "Vector of Dads: ";
    for (auto dad : std::get<0>(dfsResult)){
        std::cout << dad << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector of Heights: ";
    for (auto height : std::get<1>(dfsResult)){
        std::cout << height << " ";
    }
    std::cout << std::endl;

    std::cout << "Distance between 1 and 2: " << graph.distance(0, 1) << std::endl;
    std::cout << "Distance between 1 and 3: " << graph.distance(0, 2) << std::endl;
    std::cout << "Distance between 1 and 4: " << graph.distance(0, 3) << std::endl;
    std::cout << "Distance between 1 and 5: " << graph.distance(0, 4) << std::endl;
}
