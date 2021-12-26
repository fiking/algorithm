#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<vector<int>> maxmin(nums.size(), vector<int>(2, 0));
        for (size_t i = 0; i < nums.size(); ++i) {
            maxmin[i][0] = maxmin[i][1] = nums[i];
        }

        long long ans = 0;
        for (int delata = 1; delata < nums.size(); ++delata) {
            for (int i = 0; i < nums.size() - delata; ++i) {
                if (nums[i + delata] > maxmin[i][0]) {
                    maxmin[i][0] = nums[i + delata];
                } else if (nums[i + delata] < maxmin[i][1]) {
                    maxmin[i][1] = nums[i + delata];
                }
                ans += maxmin[i][0] - maxmin[i][1];
            }
        }

        return ans;
    }
};

void test(vector<int> &nmus) {
    Solution solution;
    long long ans = solution.subArrayRanges(nmus);
    std::cout << ans << std::endl;
}

void test1() {
    vector<int> nums = { 1,2,3 };
    test(nums);
}

void test2() {
    vector<int> nums = { 1,3,3 };
    test(nums);
}

void test3() {
    vector<int> nums = { 4, -2, -3, 4, 1 };
    test(nums);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    return 0;
}