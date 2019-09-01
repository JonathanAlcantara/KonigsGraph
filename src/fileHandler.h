#include <string>

class FileHandler {
    private:
        int vertex_qty;
    
    public:
        FileHandler();
        ~FileHandler();
        void openFile(std::string);
        void writeFile();
        int get_vertex_qty();
};