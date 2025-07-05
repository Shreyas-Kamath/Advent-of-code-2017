#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include <fstream>

struct Instruction {
    std::string op{}, lhs{}, rhs{};
};

inline auto resolve(const auto& rhs, const auto& registers) -> long long {
    return rhs.size() == 1 && std::isalpha(rhs[0]) ? registers[rhs[0] - 'a'] : std::stoi(rhs);
}

int main() {
    std::array<long long, 26> registers{};

    std::string line; std::ifstream in("data.txt");

    std::vector<Instruction> instructions;

    while (std::getline(in, line)) {
        std::istringstream iss(line);

        std::string op{}, lhs{}, rhs{};

        iss >> op >> lhs >> rhs;

        instructions.emplace_back(op, lhs, rhs);
    }

    int jump{}, sound{};

    while (jump >= 0 && jump < instructions.size()) {
        const auto& instr = instructions[jump];

        if (instr.op == "snd") sound = resolve(instr.lhs, registers);

        else if (instr.op == "set") registers[instr.lhs[0] - 'a'] = resolve(instr.rhs, registers);

        else if (instr.op == "add") registers[instr.lhs[0] - 'a'] += resolve(instr.rhs, registers);

        else if (instr.op == "mul") registers[instr.lhs[0] - 'a'] *= resolve(instr.rhs, registers);

        else if (instr.op == "mod") registers[instr.lhs[0] - 'a'] %= resolve(instr.rhs, registers);

        else if (instr.op == "rcv" && resolve(instr.lhs, registers) != 0) { std::cout << sound; break; }

        else if (instr.op == "jgz" && resolve(instr.lhs, registers) > 0) { jump += resolve(instr.rhs, registers); continue; } 

        ++jump;
    }

    return 0;
}