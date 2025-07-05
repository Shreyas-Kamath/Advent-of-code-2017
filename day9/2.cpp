#include <string>
#include <fstream>
#include <cstdio>

int main() {
    std::string line; line.reserve(5000);
    std::ifstream in("data.txt");
    std::getline(in, line);

    int total_garbage = 0;
    bool is_garbage = false, ignore_next = false;

    for (const auto& ch : line) {
        if (ignore_next) {
            ignore_next = false;
            continue;
        }

        if (is_garbage) {
            if (ch == '!') {
                ignore_next = true;
            } else if (ch == '>') {
                is_garbage = false;
            } else {
                ++total_garbage;
            }
        } else {
            if (ch == '<') {
                is_garbage = true;
            }
        }
    }

    printf("%d\n", total_garbage);
}
