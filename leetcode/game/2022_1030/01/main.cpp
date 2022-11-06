#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0;
        int sum = 0;
        for (auto num : nums) {
            if (num % 2 == 0 && num % 3 == 0) {
                sum += num;
                ++cnt;
            }
        }

        return (cnt == 0) ? 0 : ((sum ) / cnt);
    }
};

int test(vector<int> &nums) {
    Solution solution;
    std::cout << solution.averageValue(nums) << std::endl;
}

void test1() {
    vector<int> nums = {
            1, 3, 6, 10, 12, 15
    };
    test(nums);
}

void test2() {
    vector<int> nums = {
            9,3,8,4,2,5,3,8,6,1
    };
    test(nums);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    //test1();

    test2();
    return 0;
}