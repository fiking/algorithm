#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (j >= t.size()) {
                break;
            }

            if (t[j] == s[i]) {
                ++j;
            }
        }
        return t.size() - j;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}