#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> target;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == key) {
                target[nums[i + 1]]++;
            }
        }
        int max = 0;
        int maxt = 0;
        for (auto &it : target) {
            if (it.second > max) {
                maxt = it.first;
                max = it.second;
            }
        }
        return maxt;
    }
};

void test(vector<int> &nums, int key) {
    Solution solu;
    int ans = solu.mostFrequent(nums, key);
    std::cout << ans << std::endl;
}

void test1() {
    vector<int> nums = { 1, 100, 200, 1, 100 };
    int key = 1;
    test(nums, key);
}

void test2() {
    vector<int> nums = { 2, 2, 2, 2, 3 };
    int key = 2;
    test(nums, key);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
  //  test1();
    test2();
    return 0;
}