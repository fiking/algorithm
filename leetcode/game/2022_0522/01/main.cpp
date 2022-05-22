#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int len = s.size();
        int cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (letter == s[i]) {
                ++cnt;
            }
        }
        return cnt * 100 / len;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}