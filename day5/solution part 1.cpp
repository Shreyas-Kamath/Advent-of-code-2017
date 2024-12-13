#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>

int main(){
    std::ifstream in("input.txt");
    std::string num; std::vector<int> nums;
    while (std::getline(in, num)){
        nums.emplace_back(std::stoi(num));
    }

    size_t end{nums.size()};
    int position{}; int jump{}; int steps{};
    
    auto start = std::chrono::high_resolution_clock::now();

    while (position >= 0 && position < end){
        jump = nums[position];
        nums[position] += 1;
        position += jump;
        steps++;
    }
    auto end_ = std::chrono::high_resolution_clock::now();
    std::cout << steps << "\n";
    std::cout << "Time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_ - start).count()
              << " microseconds\n";
    return 0;
}