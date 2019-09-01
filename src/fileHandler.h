#include <string>

class FileHandler {
    private: 
    
    public:
        FileHandler();
        ~FileHandler();
        void openFile(std::string);
        void writeFile();
};