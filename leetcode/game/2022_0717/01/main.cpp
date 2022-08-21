#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; ) {
            if (nums[i] == nums[i + 1]) {
                i = i + 2;
                ++ans;
            } else {
                ++i;
            }
        }
        int tmp = nums.size() - ans * 2;
        vector<int> ansv = { ans, tmp};
        return ansv;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}