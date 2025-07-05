#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int main() {
    int count{};

    std::string line; std::ifstream in("data.txt");

    while (std::getline(in, line))
    {
        std::istringstream iss(line); std::string word;

        std::unordered_map<std::string, int> freq;

        while (iss >> word) ++freq[word];

        if (std::all_of(freq.begin(), freq.end(), [](const auto& pair) { return pair.second == 1; })) ++count;        
    }
    
    std::cout << count;
}