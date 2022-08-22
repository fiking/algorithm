#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] >= amount[2]) {
            return (amount[2] + amount[1] + amount[0] + 1) / 2;
        } else {
            return amount[2];
        }
    }
};

void test(vector<int> &amount) {
    Solution solution;
    int ans = solution.fillCups(amount);
    std::cout << ans << std::endl;
}

void test1() {
    vector<int> amount = { 5, 4, 4 };
    test(amount);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}