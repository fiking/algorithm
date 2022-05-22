#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int cur = ((current[0] - '0') * 10 + (current[1] - '0')) * 60 +
                  ((current[3] - '0') * 10 + (current[4] - '0'));
        int cure = ((correct[0] - '0') * 10 + (correct[1] - '0')) * 60 +
                  ((correct[3] - '0') * 10 + (correct[4] - '0'));

        int diff = cure - cur;
        if (diff < 0) {
            diff += 24 * 60;
        }

        int ans = 0;
        int tmp = diff / 60;
        if (tmp > 0) {
            ans += tmp;
            diff = diff % 60;
        }

        tmp = diff / 15;
        if (tmp > 0) {
            ans += tmp;
            diff = diff % 15;
        }

        tmp = diff / 5;
        if (tmp > 0) {
            ans += tmp;
            diff = diff % 5;
        }

        ans += diff;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}