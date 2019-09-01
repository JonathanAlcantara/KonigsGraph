#include <string>

class FileHandler {
    private:
        int vertex_qty;
        int edges_qty;
        int** edges;
        std::string filePath;
        struct edge { int v1; int v2;};
    
    public:
        FileHandler();
        ~FileHandler();
        void openFile(std::string);
        void writeFile();
        int get_vertex_qty();
        int** get_edges();
};