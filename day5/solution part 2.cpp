#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int main(){
    std::ifstream in("input.txt");
    std::string num; std::vector<int> nums;
    while (std::getline(in, num)){
        nums.emplace_back(std::stoi(num));
    }

    size_t end{nums.size()};
    int position{}; int jump{}; int steps{};

    while (position >= 0 && position < end){
        jump = nums[position];
        if (jump >= 3) nums[position] -= 1;
        else nums[position] += 1;
        position += jump;
        steps++;
    }

    std::cout << steps;
    return 0;
}