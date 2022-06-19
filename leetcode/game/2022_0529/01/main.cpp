#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> ta;
        map<char, int> sa;

        for (auto &a : target) {
            if (ta.find(a) == ta.end()) {
                ta[a] = 1;
            } else {
                ta[a] += 1;
            }
        }

        for (auto a : s) {
            if (sa.find(a) == sa.end()) {
                sa[a] = 1;
            } else {
                sa[a] += 1;
            }
        }

        int min = 101;
        for (auto t : ta) {
            auto it = sa.find(t.first);
            if (it != sa.end()) {
                int cnt = it->second / t.second;
                if (cnt < min) {
                    min = cnt;
                }
            } else {
                return 0;
            }
        }
        return min;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}