#include <fstream>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

struct Instruction
{
    std::string op{}, lhs{}, rhs{};
};

Instruction parse(const std::string& line) {
    std::stringstream ss(line); std::string op{}, lhs{}, rhs{};
    ss >> op; ss >> lhs; ss >> rhs;

    return {op, lhs, rhs};
}

int main() {
    std::ifstream in("data.txt"); std::string line{};
    std::unordered_map<char, int> registers; std::vector<Instruction> instructions;

    while (std::getline(in, line)) instructions.emplace_back(parse(line)); int mul_count{};

    for (int i{}; i < instructions.size();) {
        Instruction instr = instructions[i];

        if (instr.op == "set") {
            auto rhs = (instr.rhs.starts_with('-') || std::isdigit(instr.rhs[0])) ? std::stoi(instr.rhs) : registers[instr.rhs[0]];

            registers[instr.lhs[0]] = rhs;
            ++i;
        }

        else if (instr.op == "sub") {
            auto rhs = (instr.rhs.starts_with('-') || std::isdigit(instr.rhs[0])) ? std::stoi(instr.rhs) : registers[instr.rhs[0]];

            registers[instr.lhs[0]] -= rhs;
            ++i;
        }

        else if (instr.op == "mul") {
            auto rhs = (instr.rhs.starts_with('-') || std::isdigit(instr.rhs[0])) ? std::stoi(instr.rhs) : registers[instr.rhs[0]];
            ++mul_count;
            registers[instr.lhs[0]] *= rhs;
            ++i;
        }

        else if (instr.op == "jnz") {
            auto lhs = (instr.lhs.starts_with('-') || std::isdigit(instr.lhs[0])) ? std::stoi(instr.lhs) : registers[instr.lhs[0]];
            auto rhs = (instr.rhs.starts_with('-') || std::isdigit(instr.rhs[0])) ? std::stoi(instr.rhs) : registers[instr.rhs[0]];

            if (lhs != 0) i += rhs;
            else ++i;
        }
    }
    std::cout << mul_count;

}