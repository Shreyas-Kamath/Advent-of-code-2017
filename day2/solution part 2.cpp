#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>

int main() {

    int sum{};
    std::ifstream in("input.txt"); std::string line, num;
    while (std::getline(in, line)){
        std::stringstream ss(line); std::vector<int> vec;
        while (ss >> num){
            vec.push_back(stoi(num));
        }
        for (int i{}; i < vec.size(); ++i){
            for (int j{}; j < vec.size(); j++){
                if (i == j) continue;
                else{
                    if (vec[i] % vec[j] == 0) sum += vec[i] / vec[j];
                }
            }
        }

    }
    std::cout << sum;
}
