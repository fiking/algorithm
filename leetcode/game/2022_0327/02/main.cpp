#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        for (int i = 0; i <= nums.size() - 1; ) {
            int j = 0;
            for (j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    nums[j] = -1;
                } else {
                    break;
                }
            }
            i = j + 1;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -1) {
                ++ans;
            }
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;

        if ((nums.size() - ans) % 2 != 0) {
            ++ans;
        }
        return ans;
    }
};

void test(vector<int>& nums) {
    Solution solu;
    int ans = solu.minDeletion(nums);
    std::cout << ans << std::endl;
}

void test1() {
    vector<int> nums = { 0,1,5,4,2,4,7,2,3,0,3,0,0,9,7,5,9,4,3,9,9,2,1,6,3,1,0,7,6,6,6,0,1,7,1,9,4,9,3,3,4,5,0,3,8,7,1,8,4,5 };
    test(nums);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}