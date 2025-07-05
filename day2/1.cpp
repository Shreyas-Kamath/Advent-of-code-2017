#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

int main() {
    std::string line; std::ifstream in("data.txt");

    int sum{};

    while (std::getline(in, line)) {
        std::string num;
        std::istringstream iss(line);

        int max{INT_MIN}, min{INT_MAX};

        while (iss >> num) {
            int val = std::stoi(num);
            max = std::max(max, val);
            min = std::min(min, val);
        }

        sum += max - min;
    }
    std::cout << sum;
}