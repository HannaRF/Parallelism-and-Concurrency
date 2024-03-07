// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <chrono>


int num_threads_max = 100;

std::vector<std::string> createBlocks(std::string filePath, int N_THREADS, int &size) {
  std::vector<std::string> blocks;
  std::string line;
  std::ifstream file(filePath);
  std::stringstream buffer;
  std::string str_myfile;

  if (file) {
    buffer << file.rdbuf();
    str_myfile = buffer.str();
  } else {
    std::cout << "Unable to open file";
  }

  // print
  int len = buffer.str().length();
  size = len / N_THREADS;
  int start = 0;
  int end = size - 1;

  for (int i = 0; i < N_THREADS; i++) {

    // Se o bloco terminar no meio de uma palavra, ele pega a palavra inteira
    
    if (end < len && str_myfile[end] != ' ') {
      while (str_myfile[end] != ' ') {
        end++;
      }
    }

    std::string block = str_myfile.substr(start, end - start + 1);
    blocks.push_back(block);

    start = end;
    end += size;
  }

  str_myfile.clear();
  
  return blocks;
}

void countWords(std::string block, int &count_hate, int &count_love) {
  size_t pos = 0;
  int count_hate_thread = 0;
  int count_love_thread = 0;
  while ((pos = block.find("hate ", pos)) != std::string::npos || (pos = block.find("hate.", pos)) != std::string::npos || (pos = block.find("hate,", pos)) != std::string::npos || (pos = block.find("hate:", pos)) != std::string::npos) {
      count_hate_thread++;
      pos += 4; // Tamanho da palavra "hate"

      // std::cout << "hate: " << block.substr(pos - 4, 20) << std::endl;
  }
  
  pos = 0;
  while ((pos = block.find("love ", pos)) != std::string::npos || (pos = block.find("love.", pos)) != std::string::npos || (pos = block.find("love,", pos)) != std::string::npos || (pos = block.find("love:", pos)) != std::string::npos) {
      count_love_thread++;
      pos += 4; // Tamanho da palavra "love"
  }

  count_hate += count_hate_thread;
  count_love += count_love_thread;
}

int main () {

  for (int i = 1; i <= num_threads_max; i++) {
    auto start_overall_time = std::chrono::high_resolution_clock::now();
    int size;

    auto start_processing_time = std::chrono::high_resolution_clock::now();
    std::string filePath = "shakespeare.txt";

    std::vector<std::string> blocks = createBlocks(filePath, i, std::ref(size));

    int count_hate = 0;
    int count_love = 0;

    auto end_processing_time = std::chrono::high_resolution_clock::now();


    auto start_threads_time = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> threads;

    for (int j = 0; j < i; j++) {
      threads.push_back(std::thread(countWords, blocks[j], std::ref(count_hate), std::ref(count_love)));
    }

    for (auto &t : threads) {
      t.join();
    }
    auto end_threads_time = std::chrono::high_resolution_clock::now();

    auto end_overall_time = std::chrono::high_resolution_clock::now();

    auto processing_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_processing_time - start_processing_time);
    auto threads_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_threads_time - start_threads_time);
    auto overall_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_overall_time - start_overall_time);

    std::string mostCommon = count_hate > count_love ? "hate" : "love";

    std::cout << i << "," << size << "," << processing_time.count() << "," << threads_time.count() << "," << overall_time.count() << "," << count_hate << "," << count_love << "," << mostCommon << std::endl;

    blocks.clear();
  }

  return 0;
}