#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indexs;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                indexs.push_back(i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < indexs.size(); ++j) {
                if (abs(i - indexs[j]) <= k) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}