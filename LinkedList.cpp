#include "LinkedList.h"

std::string Version::getContent() const
{
    return content;
}

std::vector<Version *>& LinkedList::getVersions() {
    return versions;
}

void LinkedList::setVersions(const std::vector<Version *>& newVersions) {
    versions = newVersions;
}

std::size_t Version::getHashValue() const
{
    return hash_value;
}

std::size_t hash_version(std::string someString)
{
    return std::hash<std::string>()(someString);
}

LinkedList::LinkedList()
{
    // create initial version
    Version *initial_version = new Version();
    initial_version->version_number = 1;
    std::ifstream infile("file.txt");
    std::string content((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
    initial_version->content = content;
    versions.push_back(initial_version);
}

LinkedList::~LinkedList()
{
    // free up memory used by the versions
    for (Version *v : versions)
    {
        delete v;
    }
}

void LinkedList::add()
{
    // read file content
    std::ifstream infile("file.txt");
    std::string content((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));

    // check if content has changed
    if (versions.back()->content == content)
    {
        std::cout << "git322 did not detect any change to your file and will not create a new version." << std::endl;
        return;
    }
    // create new version
    Version *new_version = new Version();
    new_version->version_number = versions.back()->version_number + 1;
    new_version->content = content;
    new_version->hash_value = hash_version(content);

    versions.push_back(new_version);
    std::cout << "Your content has been added successfully." << std::endl;
}

void LinkedList::remove()
{
    int version_number;
    std::cout << "Enter the version number to remove: ";
    std::cin >> version_number;
    for (int i = 0; i < versions.size(); i++)
    {
        if (versions[i]->version_number == version_number)
        {
            delete versions[i];
            versions.erase(versions.begin() + i);
            std::cout << "Version " << version_number << " removed successfully" << std::endl;
            return;
        }
    }
    std::cout << "Version " << version_number << " not found" << std::endl;
}

void LinkedList::print() {

    if (versions.empty()) {
        std::cout << "No versions available." << std::endl;
        return;
    }

    std::cout << "Number of versions: " << versions.size() << std::endl;
    for (int i = 0; i < versions.size(); i++) {
        std::cout << "Version number: " << versions[i]->version_number << std::endl;
        std::cout << "Hash value: " << versions[i]->getHashValue() << std::endl;
        std::cout << "Content: " << versions[i]->getContent() << std::endl;
        std::cout << "\n" << std::endl;
    }
}

void LinkedList::load() {
    std::cout << "Which version would you like to load?" << std::endl;
    int version_number;
    std::cin >> version_number;
    bool version_found = false;
    for (int i = 0; i < versions.size(); i++) {
        if (versions[i]->version_number == version_number) {
            std::ofstream outfile("file.txt");
            outfile << versions[i]->content;
            outfile.close();
            std::cout << "Version " << version_number << " loaded successfully. Please refresh your text editor to see the changes." << std::endl;
            version_found = true;
            break;
        }
    }
    if (!version_found) {
        std::cout << "Please enter a valid version number. If you are not sure please press 'p' to list all valid version numbers." << std::endl;
    }
}

void LinkedList::compare() {
    int first_version_num, second_version_num;

    std::cout << "Please enter the number of the first version to compare: ";
    std::cin >> first_version_num;

    std::cout << "Please enter the number of the second version to compare: ";
    std::cin >> second_version_num;

    // get the versions based on version number
    Version* first_version = versions.at(first_version_num - 1);
    Version* second_version = versions.at(second_version_num - 1);

    std::string first_s = first_version->content;
    std::string second_s = second_version->content;
    std::istringstream iss1(first_s);
    std::istringstream iss2(second_s);
    std::string line1, line2;
    int line_number = 1;

    while (std::getline(iss1, line1) && std::getline(iss2, line2)) {
        if (line1 == line2) {
            std::cout << "Line " << line_number << ": <Identical>"<< std::endl;
        } else {
            std::cout << "Line " << line_number << ": " << line1 << " <<>> " << line2 << std::endl;
        }
        line_number++;
    }
}


void LinkedList::search() {
    std::string keyword;
    std::cout << "Please enter the keyword that you are looking for: ";
    std::cin >> keyword;
    std::vector<Version*> matches;
    for (int i = 0; i < versions.size(); i++) {
        if (versions[i]->getContent().find(keyword) != std::string::npos) {
            matches.push_back(versions[i]);
        }
    }

    if (matches.empty()) {
        std::cout << "Your keyword '" << keyword << "' was not found in any version." << std::endl;
        return;
    }

    std::cout << "The keyword '" << keyword << "' has been found in the following versions:" << std::endl;
    for (int i = 0; i < matches.size(); i++) {
        std::cout << "Version number: " << matches[i]->version_number << std::endl;
        std::cout << "Hash value: " << matches[i]->hash_value << std::endl;
        std::cout << "Content: " << matches[i]->content << std::endl;
    }
}











