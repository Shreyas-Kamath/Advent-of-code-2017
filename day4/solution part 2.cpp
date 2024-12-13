#include <unordered_set>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

bool check(const std::vector<std::string>& passphrase){
    std::unordered_set<std::string> temp;
    for (const std::string& phrase : passphrase){
        if (temp.contains(phrase)) return false;
        temp.insert(phrase);
    }
    return true;
}

int main() {
    int count{};

    std::ifstream in("input.txt"); std::string line, phrase;
    while (std::getline(in, line)){
        std::stringstream ss(line); std::vector<std::string> passphrase;
        while (ss >> phrase){
            std::sort(phrase.begin(), phrase.end());
            passphrase.push_back(phrase);
        }
        if (check(passphrase)) count++;
    }
    std::cout << count;
}