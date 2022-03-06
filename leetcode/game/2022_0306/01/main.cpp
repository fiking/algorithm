#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char x1 = s[0];
        char y1 = s[1];
        char x2 = s[3];
        char y2 = s[4];
        vector<string> ans;
        for (char x = x1; x <= x2; ++x) {
            for (char y = y1; y <= y2; ++y) {
                string tmp;
                tmp.push_back(x);
                tmp.push_back(y);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

void test(string s) {
    Solution solution;
    vector<string> ans = solution.cellsInRange(s);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}

void test1() {
    string s = "K1:L2";
    test(s);
}

void test2() {
    string s = "A1:F1";
    test(s);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    return 0;
}