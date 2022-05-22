#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<bool> special_floor = vector<bool>(1000000001, true);
public:
    int maxConsecutive1(int bottom, int top, vector<int>& special) {
        special_floor[bottom - 1] = false;
        special_floor[top + 1] = false;
        for (auto s : special) {
            special_floor[s] = false;
        }

        int start = bottom - 1;
        int max = 0;
        for (int i = start + 1; i <= top + 1; ++i) {
            if (special_floor[i]) {
                continue;
            }

            int tmp = i - start - 1;
            if (tmp > max) {
                max = tmp;
            }
            start = i;
        }
        return max;
    }

    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int start = bottom - 1;
        int end = top + 1;
        int max = 0;
        special.push_back(end);
        for (auto s : special) {
            int tmp = s - start - 1;
            if (tmp > max) {
                max = tmp;
            }
            start = s;
        }
        return max;
    }

};

void test(int bottom, int top, vector<int>& special) {
    Solution solution;
    int ans = solution.maxConsecutive(bottom, top, special);
    std::cout << ans << std::endl;
}

void test1() {
    int bottom = 2;
    int top = 9;
    vector<int> special = { 4, 6 };
    test(bottom, top, special);
    return;
}

void test2() {
    int bottom = 6;
    int top = 8;
    vector<int> special = { 7, 6, 8 };
    test(bottom, top, special);
    return;
}

void test3() {
    int bottom = 13;
    int top = 9993;
    vector<int> special = { 4321,2929,789,3757,5183,1188,9864,2558,6411,412,2647,2057,1391,7469,3578,4437,245,2217,7157,9855,4418,3185,7919,7769,2279,7872,5816,4831,5591,5269,530,8505,6851,3584,5993,1631,1192,745,5450,8608,4428,1162,7561,9297,9985,3719,2960,9159,1951,2121,655,3656,9553,6812,87,1979,6614,9784,1758,6683,5544,1332,6164,5531,538,4504,1157,3226,5586,3853,5220,9807,5440,1720,9233,853,1394,6666,1330,7805,5547,8354,3192,6053,6757,5466,7762,2094,3534,2609,6433,906,5065,9750,8413,8192,4920,1997,1529,3854 };
    test(bottom, top, special);
    return;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    return 0;
}


