# Comp322 Version Control System Project

The Comp322 Version Control System Project is an assignment developed for the Comp322 course at McGill University. It is a simple command-line tool for managing versions of a text file written in C++. It allows you to track changes to your file, compare versions, search for keywords, and more. This README provides an overview of how to use the system and understand its components.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- Input text file (e.g., "file.txt") to version

### Installation

1. Clone or download this repository to your local machine.
2. Compile the C++ files using your preferred C++ compiler. For example, using g++:

    ```bash
    g++ -o version_control main.cpp LinkedList.cpp Git322.cpp EnhancedGit322.cpp
    ```

3. Run the compiled executable:

    ```bash
    ./version_control
    ```

## Usage

Once you run the program, you'll see a menu with the following options:

- **'a' (Add)**: Add the content of your file to version control.
- **'r' (Remove)**: Remove a specific version from the list.
- **'l' (Load)**: Load a specific version from the list to your file.
- **'p' (Print)**: Display a detailed list of all versions.
- **'c' (Compare)**: Compare two versions and highlight differences.
- **'s' (Search)**: Search for a keyword in all versions.
- **'e' (Exit)**: Exit the program.

Select an option by entering the corresponding letter and follow the on-screen prompts.

## Components

- **LinkedList**: Manages versions of the file and provides basic version control operations.
- **Git322**: Acts as an interface for user interactions and delegates version control tasks to LinkedList.
- **EnhancedGit322**: Extends the basic version control system by adding the ability to save and load versions to/from a file.
- **Version**: Represents a version of the file with content, version number, and hash value.


