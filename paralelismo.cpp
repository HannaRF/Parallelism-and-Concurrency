// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <sstream>
#include <fstream>
int N_THREADS = 0;

int main () {
  std::ofstream myfile;
  std::vector<std::string> blocks;
  int count_hate = 0;
  int count_love = 0;

  // divide txt in blocks to begin the parallelism
  // 1. read the file

  std::string line;
  std::ifstream file("shakespeare.txt");
  std::stringstream buffer;

  if (file) {
    buffer << file.rdbuf();
    std::string str_myfile = buffer.str();
  } else {
    std::cout << "Unable to open file";
  }

  // print
  std::cout << buffer.str() << std::endl;

  // for (block in blocks)
  // {
  //  count_hate += std::count(block.begin(), block.end(), "hate");
  //  count_love += std::count(block.begin(), block.end(), "love");
  // }

  return 0;
}


