#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        vector<bool> cnt(10, false);
        int c = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i - 1] == num[i]) {
                ++c;
            } else {
                c = 1;
                continue;
            }

            if (c >= 3) {
                cnt[num[i] - '0'] = true;
            }
        }
        for (int i = 9; i >= 0; --i) {
            if (cnt[i]) {
                string ans;
                ans.push_back('0' + i);
                ans.push_back('0' + i);
                ans.push_back('0' + i);
                return ans;
            }
        }
        return "";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}