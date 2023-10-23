#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iterator>
#include <sstream>

struct Version
{
    int version_number;
    std::string content;
    std::size_t hash_value;
    std::string getContent() const;
    std::size_t getHashValue() const;
};

class LinkedList
{
private:
    std::vector<Version *> versions;

public:
    LinkedList();
    ~LinkedList();

    void add();
    void remove();
    void print();
    void load();
    void compare();
    void search();

    // Define get and set methods for the versions vector
    std::vector<Version *>& getVersions();
    void setVersions(const std::vector<Version *>& newVersions);
};
