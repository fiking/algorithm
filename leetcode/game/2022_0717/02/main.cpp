#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> maxinum;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            int tmp = nums[i];
            while (tmp != 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
            std::cout << "sum = " << sum << " num = " << nums[i] <<std::endl;
            auto it = maxinum.find(sum);
            if (it == maxinum.end()) {
                maxinum[sum].push_back(i);
            } else if (it->second.size() == 1) {
                maxinum[sum].push_back(i);
            } else {
                int tmp1 = 0;
                if (nums[maxinum[sum][0]] < nums[i]) {
                    tmp1 = maxinum[sum][0];
                    maxinum[sum][0] = i;
                } else {
                    tmp1 = i;
                }

                if (nums[maxinum[sum][1]] < nums[tmp1]) {
                    maxinum[sum][1] = tmp1;
                }
            }
        }

        int ans = 0;
        for (auto &mm : maxinum) {
            if (mm.second.size() == 2) {
                int sum = nums[mm.second[0]] + nums[mm.second[1]];
                std::cout << mm.first << " sum = " << sum << std::endl;
                if (sum > ans) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
};

void test(vector<int> &nums) {
    Solution solution;
    int ans = solution.maximumSum(nums);
    std::cout << ans << std::endl;
}

void test1() {
    vector<int> nums = { 279,169,463,252,94,455,423,315,288,64,494,337,409,283,283,477,248,8,89,166,188,186,128 };
    test(nums);
}

void test2() {
    vector<int> nums = { 18,43,36,13,7 };
    test(nums);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}