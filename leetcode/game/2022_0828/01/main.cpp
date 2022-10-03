#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < queries.size(); ++i) {
            int j = 0;
            int sum = 0;
            for (; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum > queries[i]) {
                    break;
                }
            }
            ans.push_back(j);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}