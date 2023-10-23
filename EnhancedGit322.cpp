#include "Git322.h"
#include <fstream>
#include <sstream>

class EnhancedGit322 : public Git322 {
public:
    EnhancedGit322();
    ~EnhancedGit322();

    void add() override;
    void remove() override;
    void load() override;

private:
    void saveVersionsToFile();
    void loadVersionsFromFile();
    const std::string VERSIONS_FILENAME = "versions.dat";
};

// Constructor
EnhancedGit322::EnhancedGit322() {
    loadVersionsFromFile();
}

// Destructor
EnhancedGit322::~EnhancedGit322() {
}

// Override add method
void EnhancedGit322::add() {
    Git322::add();
    saveVersionsToFile();
}

// Override remove method
void EnhancedGit322::remove() {
    Git322::remove();
    saveVersionsToFile();
}

// Override load method
void EnhancedGit322::load() {
    Git322::load();
}

// Helper method to save versions to a file
void EnhancedGit322::saveVersionsToFile() {
    std::ofstream outfile(VERSIONS_FILENAME, std::ios::binary);
    for (Version *version : myList.getVersions()) {
        outfile.write(reinterpret_cast<char *>(version), sizeof(Version));
    }
    outfile.close();
}

// Helper method to load versions from a file
void EnhancedGit322::loadVersionsFromFile() {
    std::ifstream infile(VERSIONS_FILENAME, std::ios::binary);
    if (infile.is_open()) {
        while (!infile.eof()) {
            Version *version = new Version();
            infile.read(reinterpret_cast<char *>(version), sizeof(Version));
            if (infile.gcount() == sizeof(Version)) {
                myList.getVersions().push_back(version);
            } else {
                delete version;
            }
        }
        infile.close();
    }
}
