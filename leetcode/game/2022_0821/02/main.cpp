#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> nums(10, 0);
        for (int i = 0; i < num.size(); ++i) {
            nums[num[i] - '0']++;
        }

        char last = -1;
        string ans;
        for (int i = 9; i >= 0; --i) {
            if (nums[i] == 0) {
                continue;
            }

            for (int j = 0; j < nums[i] / 2; ++j) {
                if (i == 0 && ans.empty()) {
                    break;
                }
                ans += '0' + i;
            }
            if (last == -1 && nums[i] % 2 != 0) {
                last = '0' + i;
            }
        }
//       std::cout << ans << std::endl;
        string ans1 = ans;
        if (last != -1) {
            ans1 += last;
        }
        for (int i = ans.size() - 1; i >= 0; --i) {
            ans1 += ans[i];
        }
        if (ans1.empty()) {
            return "0";
        }
        return ans1;
    }
};

void test(string num) {
    Solution solu;
    string ans = solu.largestPalindromic(num);
    std::cout << ans << std::endl;
}

void test1() {
    string num = "444947137";
    test(num);
}

void test2() {
    string num = "00";
    test(num);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    return 0;
}