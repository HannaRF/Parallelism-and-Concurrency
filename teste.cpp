#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string line = "I hate you, I love you";

    std::cout << "Line: " << line << std::endl;
    std::cout << "Line[10:16]: " << line.substr(10, 6) << std::endl;

    return 0;
}