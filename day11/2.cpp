#include <string>
#include <fstream>
#include <ranges>

int main() {
    std::string line; line.reserve(20000); std::ifstream in("data.txt");

    std::getline(in, line);

    int x{}, y{}, z{};

    std::string dir; int max_dist{};

    for (const auto& section: line | std::views::split(',')) {

        std::string direction(section.begin(), section.end());

        if (direction == "n") { ++y; --z; }
        else if (direction == "ne") { ++x; --z; }
        else if (direction == "se") { ++x; --y; }
        else if (direction == "s") { --y; ++z; }
        else if (direction == "sw") { --x; ++z; }
        else if (direction == "nw") { --x; ++y; }

        max_dist = std::max(max_dist, std::max({ abs(x), abs(y), abs(z) }));
    }
    
    printf("%d", max_dist);
}