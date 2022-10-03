#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int max = 0;

        int cur = 1;
        int curm = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == curm) {
                ++cur;
                continue;
            }

            if (curm > max) {
                max = curm;
                ans = cur;
            } else if (curm == max && cur > ans) {
                ans = cur;
            }

            curm = nums[i];
            cur = 1;
        }

        if (curm > max) {
            max = curm;
            ans = cur;
        } else if (curm == max && cur > ans) {
            ans = cur;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}