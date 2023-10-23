#ifndef ENHANCEDGIT322_H
#define ENHANCEDGIT322_H

#include "Git322.h"

class EnhancedGit322 : public Git322 {
private:
    std::string filename = "versions.txt"; // the filename to save the versions

    // helper function to save the versions to file
    void saveVersionsToFile();

    // helper function to load the versions from file
    void loadVersionsFromFile();

public:
    EnhancedGit322();

    ~EnhancedGit322();

    // redefine the add method to save the versions to file after adding a new version
    void add() override;

    // redefine the remove method to save the versions to file after removing a version
    void remove() override;

    // redefine the load method to save the versions to file after loading a version
    void load() override;
};

#endif /* ENHANCEDGIT322_H */
