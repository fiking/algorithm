#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); ++i) {
            for (auto coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
};

void test(vector<int>& coins, int amount) {
    Solution solution;
    int ans = solution.coinChange(coins, amount);
    std::cout << ans << std::endl;
}

void test1() {
    vector<int> coins = { 1, 2, 5 };
    int amount = 11;
    test(coins, amount);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}