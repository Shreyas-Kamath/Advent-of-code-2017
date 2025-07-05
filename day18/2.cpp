#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

struct Instruction {
    std::string op{}, lhs{}, rhs{};
};

struct Program {
    std::vector<Instruction> instructions;
    std::array<long long, 26> registers{};
    std::queue<long long> queue;

    int instruction_pointer{};

    bool terminated{false};
    bool waiting{false};

    int id{};
};

inline long long resolve(const auto& str, const auto& registers) {
    return str.size() == 1 && std::isalpha(str[0]) ? registers[str[0] - 'a'] : std::stoll(str);
}

void run(Program& prog, auto& other_queue, int& counter) {
    if (prog.instruction_pointer < 0 || prog.instruction_pointer >= prog.instructions.size()) {
        prog.terminated = true;
        return;
    }

    const auto& instr = prog.instructions[prog.instruction_pointer];

    if (instr.op == "snd") {
        other_queue.push(resolve(instr.lhs, prog.registers));
        if (prog.id == 1) ++counter;
        ++prog.instruction_pointer;
    }

    else if (instr.op == "rcv") {
        if (prog.queue.empty()) {
            prog.waiting = true;
            return;
        } else {
            prog.registers[instr.lhs[0] - 'a'] = prog.queue.front();
            prog.queue.pop();
            ++prog.instruction_pointer;
            prog.waiting = false;
        }
    }

    else if (instr.op == "set") {
        prog.registers[instr.lhs[0] - 'a'] = resolve(instr.rhs, prog.registers);
        ++prog.instruction_pointer;
    }

    else if (instr.op == "add") {
        prog.registers[instr.lhs[0] - 'a'] += resolve(instr.rhs, prog.registers);
        ++prog.instruction_pointer;
    }

    else if (instr.op == "mul") {
        prog.registers[instr.lhs[0] - 'a'] *= resolve(instr.rhs, prog.registers);
        ++prog.instruction_pointer;
    }

    else if (instr.op == "mod") {
        prog.registers[instr.lhs[0] - 'a'] %= resolve(instr.rhs, prog.registers);
        ++prog.instruction_pointer;
    }

    else if (instr.op == "jgz") {
        if (resolve(instr.lhs, prog.registers) > 0) 
        prog.instruction_pointer += resolve(instr.rhs, prog.registers);
        else ++prog.instruction_pointer;
    }
}

int main() {
    std::ifstream in("data.txt"); std::string line;

    std::vector<Instruction> instructions;

    while (std::getline(in, line)) {
        
        std::string op{}, lhs{}, rhs{};

        std::istringstream iss(line);
        iss >> op >> lhs;
        if (iss >> rhs) instructions.emplace_back(op, lhs, rhs);
        else instructions.emplace_back(op, lhs, "");
    }

    Program p0, p1;
    p0.instructions = instructions; p0.id = 0; p0.registers['p' - 'a'] = 0;
    p1.instructions = instructions; p1.id = 1; p1.registers['p' - 'a'] = 1;

    int count_if_id_1{};

    while (true) {

        if (p0.terminated && p1.terminated || p0.waiting && p1.waiting) break;

        if (!p0.waiting || !p0.terminated) run(p0, p1.queue, count_if_id_1);
        if (!p1.waiting || !p1.terminated) run(p1, p0.queue, count_if_id_1);
    }

    std::cout << count_if_id_1;
}