#include "konigs.h"

KonigsGraph::KonigsGraph(std::string file){
    KonigsGraph::loadGraphFromFile(file);
    KonigsGraph::stats();
}
