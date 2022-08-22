#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        while (true) {
            int min = 101;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] != 0 && nums[i] < min) {
                    min = nums[i];
                }
            }

            if (min == 101) {
                break;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    continue;
                }
                nums[i] = nums[i] - min;
            }
            ++ans;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}