#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        struct NumIndex {
            int map;
            int index;
        };
        vector<NumIndex> nums_map(nums.size(), {0, 0});
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            if (tmp == 0) {
                nums_map[i].map =  mapping[tmp];
            }
            int mask = 1;
            while (tmp != 0) {
                nums_map[i].map = nums_map[i].map + mapping[tmp % 10] * mask;
                tmp /= 10;
                mask *= 10;
            }
            nums_map[i].index = i;
        }

        sort(nums_map.begin(), nums_map.end(), [&](const NumIndex &a, const NumIndex &b) {
            if (a.map != b.map) {
              return a.map < b.map;
            }
            return a.index < b.index;
        });

        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = nums[nums_map[i].index];
        }
        return ans;
    }
};

void test(vector<int> &map, vector<int> &nums) {
    Solution solu;
    vector<int> ans = solu.sortJumbled(map, nums);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}

void test1() {
    vector<int> map = { 8,9,4,0,2,1,3,5,7,6 };
    vector<int> nums = { 991, 338, 38 };
    test(map, nums);
}

void test2() {
    vector<int> map = { 0,1,2,3,4,5,6,7,8,9 };
    vector<int> nums = { 789,456,123 };
    test(map, nums);
}

void test3() {
    vector<int> map = { 9,8,7,6,5,4,3,2,1,0 };
    vector<int> nums = { 0,1,2,3,4,5,6,7,8,9 };
    test(map, nums);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
 //   test1();
 //   test2();
    test3();
    return 0;
}