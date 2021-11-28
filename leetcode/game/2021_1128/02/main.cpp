#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }

        vector<long> prefix(nums.size() + 1, 0);
        for (int i = 1; i < nums.size() + 1; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - k < 0 || i + k >= nums.size()) {
                ans.push_back(-1);
                continue;
            }

            long sum = prefix[i + k + 1] - prefix[i - k];
            int ave = sum / (2 * k + 1);
            ans.push_back(ave);
        }
        return ans;
    }
};

void test1() {
    vector<int> nums = { 7,4,3,9,1,8,5,2,6 };
    int k = 3;
    Solution solu;
    auto ans = solu.getAverages(nums, k);
    for (auto a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void test2() {
    vector<int> nums = { 100000 };
    int k = 0;
    Solution solu;
    auto ans = solu.getAverages(nums, k);
    for (auto a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void test3() {
    vector<int> nums = { 8 };
    int k = 100000;
    Solution solu;
    auto ans = solu.getAverages(nums, k);
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
    return 0;
}