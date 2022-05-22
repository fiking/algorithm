#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int prev = 0;
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            int pvalue = -1;
            for (int j = i - 1; j >= prev; ++j) {
                if (nums[j] != nums[i]) {
                    pvalue = j;
                    break;
                }
            }
            if (pvalue == -1) {
                continue;
            }

            int nvalue = -1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] != nums[i]) {
                    nvalue = j;
                    break;
                }
            }
            if (nvalue == -1) {
                continue;
            }

            if ((nums[pvalue] > nums[i] && nums[nvalue] > nums[i]) ||
                (nums[pvalue] < nums[i] && nums[nvalue] < nums[i])){
                ++ans;
            }
            i = nvalue - 1;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}