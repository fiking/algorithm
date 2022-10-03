#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int cur = 1;
        char cs = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] - cs == 1) {
                cur++;
            } else {
                if (cur > ans) {
                    ans = cur;
                }
                cur = 1;
            }
            cs = s[i];
        }
        if (cur > ans) {
            return cur;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}