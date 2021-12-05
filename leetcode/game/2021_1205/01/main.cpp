#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());

        vector<int> ans;
        map<int, int> ans_map;
        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] == 0) continue;

            for (int j = 0; j < digits.size(); ++j) {
                if (j == i) continue;

                for (int k = 0; k < digits.size(); ++k) {
                    if (k == i || k == j) continue;

                    if (digits[k] % 2 != 0) continue;

                    int tmp = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (ans_map.count(tmp) != 0) continue;

                    ans_map.insert(make_pair(tmp, 1));
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};

void test1() {
    vector<int> digits = { 2, 1, 3, 0 };
    Solution solution;
    auto ans = solution.findEvenNumbers(digits);
    for (int i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
}

void test2() {
    vector<int> digits = { 2, 2, 8, 8, 2 };
    Solution solution;
    auto ans = solution.findEvenNumbers(digits);
    for (int i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
}

void test3() {
    vector<int> digits = { 3, 7, 5 };
    Solution solution;
    auto ans = solution.findEvenNumbers(digits);
    for (int i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
}

void test4() {
    vector<int> digits = { 0, 2, 0, 0 };
    Solution solution;
    auto ans = solution.findEvenNumbers(digits);
    for (int i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
}

void test5() {
    vector<int> digits = { 0, 0, 0 };
    Solution solution;
    auto ans = solution.findEvenNumbers(digits);
    for (int i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}