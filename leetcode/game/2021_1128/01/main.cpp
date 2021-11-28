#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (target == nums[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

void test1() {
    vector<int> nums = { 1, 2, 5, 2, 3 };
    int target = 2;
    Solution solu;
    auto ans = solu.targetIndices(nums, target);
    for (auto a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void test2() {
    vector<int> nums = { 1, 2, 5, 2, 3 };
    int target = 3;
    Solution solu;
    auto ans = solu.targetIndices(nums, target);
    for (auto a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void test3() {
    vector<int> nums = { 1,2,5,2,3 };
    int target = 5;
    Solution solu;
    auto ans = solu.targetIndices(nums, target);
    for (auto a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void test4() {
    vector<int> nums = { 1,2,5,2,3 };
    int target = 4;
    Solution solu;
    auto ans = solu.targetIndices(nums, target);
    for (auto a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    test4();

    return 0;
}