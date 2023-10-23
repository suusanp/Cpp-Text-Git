#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iterator>
#include <sstream>
#include "LinkedList.h"
#include "Git322.h"
#include "EnhancedGit322.h"


int main()
{
    // create initial version
    EnhancedGit322 myGit;

    std::cout << "Welcome to the Comp322 file versioning system!" << std::endl;
    std::cout << "To add the content of your file to version control press 'a'" << std::endl;
    std::cout << "To remove a version press 'r'" << std::endl;
    std::cout << "To load a version press 'l'" << std::endl;
    std::cout << "To print to the screen the detailed list of all versions press 'p'" << std::endl;
    std::cout << "To compare any 2 versions press 'c'" << std::endl;
    std::cout << "To search versions for a keyword press 's'" << std::endl;
    std::cout << "To exit press 'e'" << std::endl;
    while (true)
    {
        char choice;
        std::cin >> choice;

        switch (choice)
        {
        case 'a':
            myGit.add();
            break;
        case 'r':
            myGit.remove();
            break;
        case 'l':
            myGit.load();
            break;
        case 'p':
            myGit.print();
            break;
        case 'c':
            myGit.compare();
            break;
        case 's':
            myGit.search();
            break;
        case 'e':
            std::cout << "Exiting the program" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }

        std::cout << "\n";
    }

    return 0;
}