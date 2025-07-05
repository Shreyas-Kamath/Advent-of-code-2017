#include <string>
#include <fstream>

int main() {

    std::string line; line.reserve(5000);
    std::ifstream in("data.txt");

    std::getline(in, line);

    int depth{}, score{};

    bool is_garbage{false}, ignore_next{false};

    for (const auto& ch: line) {
        if (ignore_next) { ignore_next = false; continue; }

        if (is_garbage) {
            if (ch == '!') { ignore_next = true; }
            else if (ch == '>') { is_garbage = false; }

            else continue;
        }

        else {
            if (ch == '<') is_garbage = true;

            else if (ch == '{') { ++depth; score += depth; }
            else if (ch == '}') { --depth; }
        }
    }
    printf("%d", score);
}