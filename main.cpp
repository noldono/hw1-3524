#include "stack.hpp"
#include <iostream>
#include <fstream>

bool executeCommand(std::string line, Stack &s, double &result);
void add(Stack &s, double &result);
void average(Stack &s, double &result);
void multiply(Stack &s, double &result);

int main(int argc, char *argv[]) {
    Stack s;
    double result = 0.0;
    // Take from standard input
    if (argc == 1) {
        // Standard input could still contain contents from a file or user input
        std::string line;
        while(std::getline(std::cin, line)) {
            if(executeCommand(line, s, result)) {
                std::cout << result << std::endl;
                return 0;
            }
            s.push(std::stod(line));
        }

    } else if (argc == 2) {
        // Args would be ./hw1 [filename]
        std::string filename = std::string(argv[1]);
        std::ifstream file(filename);
        std::string line;

        if(!file.good()) {
            std::cerr << "Error: Invalid file name" << std::endl;
            return -1;
        }

        while(std::getline(file, line)) {
            if(executeCommand(line, s, result)) {
                std::cout << result << std::endl;
                return 0;
            }
            s.push(std::stod(line));
        }

    } else {
        // If args are >2 then its an error
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return -1;
    }

    return 0;
}

bool executeCommand(std::string line, Stack &s, double &result) {
    if(line == "add") {
        if(s.size() == 0) {
            return false;
        }
        add(s, result);
        return true;
    } else if (line == "multiply") {
        if(s.size() == 0) {
            return false;
        }
        multiply(s, result);
        return true;
    } else if (line == "average") {
        if(s.size() == 0) {
            return false;
        }
        average(s, result);
        return true;
    }
    return false;
}

void add(Stack &s, double &result) {
    while(s.size() != 0) {
        result += s.top();
        s.pop();
    }
}

void average(Stack &s, double &result) {
    int n = 0;
    while (s.size() != 0) {
        result += s.top();
        n++;
        s.pop();
    }
    result = (result / n);
}

void multiply(Stack &s, double &result) {
    while(s.size() != 0) {
        result *= s.top();
        s.pop();
    }
}

