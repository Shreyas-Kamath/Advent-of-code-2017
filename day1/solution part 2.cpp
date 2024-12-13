#include <fstream>
#include <string>
#include <iostream>

int main() {
    std::ifstream in("input.txt");
    std::string content;
    std::getline(in, content);
    in.close();

    int sum{};
    for (int i{}; i < content.length(); ++i){
        if (content[i] == content[(i + content.length() / 2) % content.length()]) sum += (content[i] - '0');
    }
    std::cout << sum;
    return 0;
}