#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int max_strength(int port, auto& connectors, auto& used) {
    int best{};

    for (int i{}; i < connectors.size(); ++i) {
        if (used[i]) continue;

        auto [a, b] = connectors[i];

        if (a == port || b == port) {
            used[i] = true;
            int next = (a == port) ? b : a;
            best = std::max(best, a + b + max_strength(next, connectors, used));
            used[i] = false;
        }
    }

    return best;
}

int main() {
    const char* format = "%d/%d";

    std::string line; std::ifstream in("data.txt");

    std::vector<std::pair<int, int>> connectors;

    while (std::getline(in, line)) {
        int lhs{}, rhs{};

        if (std::sscanf(line.c_str(), format, &lhs, &rhs) == 2) connectors.emplace_back(lhs, rhs);
    }

    std::vector<bool> used(connectors.size(), false);

    std::cout << max_strength(0, connectors, used);

}
