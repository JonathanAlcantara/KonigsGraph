#include "konigs.h"
#include <chrono>

int main(){
    std::cout << "Hello world, Konigs!" << std::endl;

    std::cout << "Starting AS Graph" << std::endl;
    unsigned diameter;
    KonigsGraph as_graph("data/as_graph.txt", false, true);
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) as_graph.BFS(i);
    auto diff = std::chrono::steady_clock::now() - start;
    std::cout << "Running 1000 BFS" << std::endl;
    std::cout << "Time Spent:" << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) as_graph.DFS(i);
    diff = std::chrono::steady_clock::now() - start;
    std::cout << "Running 1000 DFS" << std::endl;
    std::cout << "Time Spent:" << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    std::cout << "Spanning Trees - BFS" << std::endl;
    std::tuple<std::vector<unsigned>, std::vector<unsigned>> current_tree = as_graph.BFS(0);
    std::cout << "Father of 10 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = as_graph.BFS(1);
    std::cout << "Father of 10 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = as_graph.BFS(2);
    std::cout << "Father of 10 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[29] << std::endl;

    std::cout << "Spanning Trees - DFS" << std::endl;
    current_tree = as_graph.DFS(0);
    std::cout << "Father of 10 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = as_graph.DFS(1);
    std::cout << "Father of 10 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = as_graph.DFS(2);
    std::cout << "Father of 10 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[29] << std::endl;

    std::cout << "Distance Between 10 and 20: " << as_graph.distance(10, 20) << std::endl;
    std::cout << "Distance Between 10 and 30: " << as_graph.distance(10, 30) << std::endl;
    std::cout << "Distance Between 20 and 30: " << as_graph.distance(20, 30) << std::endl;
    
    std::cout << "Number of Connected Components of AS Graph: " << as_graph.connectedComponents().size() << std::endl;

    start = std::chrono::steady_clock::now();
    diameter = as_graph.diameter(0, -1);
    diff = std::chrono::steady_clock::now() - start; 
    std::cout << "Diameter of AS Graph: " << diameter << std::endl;
    std::cout << "Time Spent:" << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    as_graph.~KonigsGraph();
    std::cout << std::endl;

    std::cout << "Starting DBLP Graph" << std::endl;
    KonigsGraph dblp_graph("data/dblp.txt", false, true);
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) dblp_graph.BFS(i);
    diff = std::chrono::steady_clock::now() - start;
    std::cout << "Running 1000 BFS" << std::endl;
    std::cout << "Time Spent:" << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) dblp_graph.DFS(i);
    diff = std::chrono::steady_clock::now() - start;
    std::cout << "Running 1000 DFS" << std::endl;
    std::cout << "Time Spent:" << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    std::cout << "Spanning Trees - BFS" << std::endl;
    current_tree = dblp_graph.BFS(0);
    std::cout << "Father of 10 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = dblp_graph.BFS(1);
    std::cout << "Father of 10 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[19] << std::endl; 
    std::cout << "Father of 30 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = dblp_graph.BFS(2);
    std::cout << "Father of 10 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[29] << std::endl;

    std::cout << "Spanning Trees - DFS" << std::endl;
    current_tree = dblp_graph.DFS(0);
    std::cout << "Father of 10 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = dblp_graph.DFS(1);
    std::cout << "Father of 10 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[19] << std::endl; 
    std::cout << "Father of 30 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = dblp_graph.DFS(2);
    std::cout << "Father of 10 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[29] << std::endl;

    std::cout << "Distance Between 10 and 20: " << dblp_graph.distance(10, 20) << std::endl;
    std::cout << "Distance Between 10 and 30: " << dblp_graph.distance(10, 30) << std::endl;
    std::cout << "Distance Between 20 and 30: " << dblp_graph.distance(20, 30) << std::endl;
    
    //std::cout << "Number of Connected Components of DBLP Graph: " << dblp_graph.connectedComponents().size() << std::endl;

    start = std::chrono::steady_clock::now();
    diameter = dblp_graph.diameter(0, 1000);
    diff = std::chrono::steady_clock::now() - start; 
    std::cout << "Current Diameter of DBLP Graph: " << diameter << std::endl;
    std::cout << "Estimated Total Time:" << std::chrono::duration <double, std::ratio<3600>> (diff).count()*1397.510 << " hours" << std::endl;

    dblp_graph.~KonigsGraph();
    std::cout << std::endl;

    std::cout << "Starting LiveJournal Graph" << std::endl;
    KonigsGraph liveJournal_graph("data/live_journal.txt", false, true);
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) liveJournal_graph.BFS(i);
    diff = std::chrono::steady_clock::now() - start;
    std::cout << "Running 1000 BFS" << std::endl;
    std::cout << "Time Spent:" << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) liveJournal_graph.DFS(i);
    diff = std::chrono::steady_clock::now() - start;
    std::cout << "Running 1000 DFS" << std::endl;
    std::cout << "Time Spent:" << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    std::cout << "Spanning Trees - BFS" << std::endl;
    current_tree = liveJournal_graph.BFS(0);
    std::cout << "Father of 10 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 1: "<< std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = liveJournal_graph.BFS(1);
    std::cout << "Father of 10 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = liveJournal_graph.BFS(2);
    std::cout << "Father of 10 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[29] << std::endl;

    std::cout << "Spanning Trees - DFS" << std::endl;
    current_tree = liveJournal_graph.DFS(0);
    std::cout << "Father of 10 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 1: "<< std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 1: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = liveJournal_graph.DFS(1);
    std::cout << "Father of 10 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 2: " << std::get<0>(current_tree)[29] << std::endl;

    current_tree = liveJournal_graph.DFS(2);
    std::cout << "Father of 10 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[9] << std::endl;
    std::cout << "Father of 20 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[19] << std::endl;
    std::cout << "Father of 30 of Spanning Tree on Vertex 3: " << std::get<0>(current_tree)[29] << std::endl;
    std::cout << "Distance Between 10 and 20: " << liveJournal_graph.distance(10, 20) << std::endl;
    std::cout << "Distance Between 10 and 30: " << liveJournal_graph.distance(10, 30) << std::endl;
    std::cout << "Distance Between 20 and 30: " << liveJournal_graph.distance(20, 30) << std::endl;
    
    //std::cout << "Number of Connected Components of LiveJournal Graph: " << liveJournal_graph.connectedComponents().size() << std::endl;

    start = std::chrono::steady_clock::now();
    diameter = liveJournal_graph.diameter(1234, 1000);
    diff = std::chrono::steady_clock::now() - start; 
    std::cout << "Current Diameter of LiveJournal Graph: " << diameter << std::endl;
    std::cout << "Estimated Total Time:" << std::chrono::duration <double, std::ratio<3600>> (diff).count()*3997.962 << " hours" << std::endl;

    liveJournal_graph.~KonigsGraph();
}
