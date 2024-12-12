#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int max(const std::vector<int>& vec){
    int max = vec[0];
    for (auto& elem: vec){
        if (elem > max) max = elem;
    }
    return max;
}

int min(const std::vector<int>& vec){
    int min = vec[0];
    for (auto& elem: vec){
        if (elem < min) min = elem;
    }
    return min;
}


int main() {

    int sum{}; 
    std::ifstream in("input.txt"); std::string line, num;
    while (std::getline(in, line)){
        std::stringstream ss(line); std::vector<int> vec;
        while (ss >> num){
            vec.push_back(stoi(num));
        }
        sum += max(vec) - min(vec);

    }
    std::cout << sum;
}
