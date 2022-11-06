#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        vector<vector<long long>> dp(nums.size(), vector<long long>(nums.size(), -1));
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][i] = nums[i];
            if (k == 1) {
                if (dp[i][i] > ans) {
                    ans = dp[i][i];
                }
                continue;
            }
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] == nums[j] || i - j > k) {
                    break;
                }

                if (dp[j][i - 1] == -1) {
                    continue;
                }

                dp[j][i] = dp[j][i - 1] + nums[i];
                if ((i - j + 1) == k && dp[j][i] > ans)
                    ans = dp[j][i];
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}