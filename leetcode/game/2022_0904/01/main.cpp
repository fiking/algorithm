#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < s.size(); ++i) {
            int next = distance[s[i] - 'a'] + i + 1;
            if (next  >= s.size()) {
                return false;
            }

            if (s[i] != s[next]) {
                return false;
            }

            distance[s[i] - 'a'] = -1;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}