#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < nums[min]) {
                min = i;
            }
            if (nums[i] > nums[max]) {
                max = i;
            }
        }

        int min_l = min - 0 + 1;
        int max_l = max - 0 + 1;
        int min_r = nums.size() - min;
        int max_r = nums.size() - max;

        // -> l
        int ans = max_l > min_l ? max_l : min_l;

        // -> r
        if (ans > max_r && ans > min_r) {
            ans = max_r > min_r ? max_r : min_r;
        }

        int tmp  = (min_l + max_r) < (min_r + max_l) ? (min_l + max_r) : (min_r + max_l);
        if (tmp < ans) {
            ans = tmp;
        }
        return ans;
    }
};

void test1() {
    vector<int> nums = { 2,10,7,5,4,1,8,6 };
    Solution solution;
    int ans = solution.minimumDeletions(nums);
    std::cout << ans << std::endl;
}

void test2() {
    vector<int> nums = { 101 };
    Solution solution;
    int ans = solution.minimumDeletions(nums);
    std::cout << ans << std::endl;
}

void test3() {
    vector<int> nums = { 0,-4,19,1,8,-2,-3,5 };
    Solution solution;
    int ans = solution.minimumDeletions(nums);
    std::cout << ans << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    return 0;
}