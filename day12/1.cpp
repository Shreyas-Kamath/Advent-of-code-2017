#include <sstream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <queue>
#include <vector>

int main() {
    std::string line; std::ifstream in("data.txt");

    std::unordered_map<std::string, std::vector<std::string>> adj_list;

    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string lhs, arrow, token;
        iss >> lhs >> arrow;

        while (iss >> token) {
            if (token.back() == ',') token.pop_back();
            adj_list[lhs].push_back(token);
            adj_list[token].push_back(lhs); 
        }
    }

    std::unordered_map<std::string, bool> visited;
    std::queue<std::string> q;

    q.push("0"); visited["0"] = true; int count{1};

    while (!q.empty()) {
        auto front = q.front(); q.pop();

        for (const auto& neighbor: adj_list[front]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                ++count;
            }
        }
    }
    printf("%d", count);
}