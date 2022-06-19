#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ) {
            ++ans;
            int j = i + 1;
            for (; j < nums.size(); ++j) {
                if (nums[j] - nums[i] > k) {
                    break;
                }
            }
            i = j;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}