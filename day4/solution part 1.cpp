#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

bool is_valid(const std::unordered_map<std::string, int>& seq){
    for (auto& pair: seq){
        if (pair.second != 1) return false;
    }
    return true;
}

int main() {
    std::ifstream in("input.txt");
    std::string line, passphrase;
    int count{};
    while (std::getline(in, line)){
        std::stringstream ss(line); std::unordered_map<std::string, int> sequence;
        while (ss >> passphrase){
            sequence[passphrase]++;
        }
        if (is_valid(sequence)) count++;
    }
    in.close();
    std::cout << count;
    return 0;
}