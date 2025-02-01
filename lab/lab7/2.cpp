#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <random>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> strs;
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        strs.push_back(str);
    }
    sort(strs.begin(), strs.end(), [](std::string &a, std::string &b) {
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    });
    for (auto& str : strs) {
        std::cout << str << std::endl;
    }
    return 0;
}
