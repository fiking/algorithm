#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> operas;
        unordered_map<int, int> reoperas;

        for (int i = 0; i < operations.size(); ++i) {
            auto it = reoperas.find(operations[i][0]);
            if (it != reoperas.end()) {
                operas[it->second] = operations[i][1];
                reoperas[operations[i][1]] = it->second;
                reoperas.erase(it);
            } else {
                operas[operations[i][0]] = operations[i][1];
                reoperas[operations[i][1]] = operations[i][0];
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            auto it = operas.find(nums[i]);
            if (it != operas.end()) {
                nums[i] = it->second;
            }
        }
        return nums;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}