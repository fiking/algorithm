#include <iostream>

using namespace std;



class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = Number1(num1);
        int cnt2 = Number1(num2);

        int cnt = cnt2 - cnt1;
        int ans = 0;

        if (cnt > 0) {
            int left = 0;
            while (cnt > 0) {
                if ((num1 & (1 << left)) == 0) {
                    num1 = num1 | (1 << left);
                    cnt--;
                }
                left++;
            }
        } else {
            int left = 0;
            cnt = -cnt;
            while (cnt > 0) {
                if ((num1 & (1 << left)) == (1 << left)) {
                    num1 = num1 ^ (1 << left);
                    cnt--;
                }
                left++;
            }
        }
        return num1;
    }

    int Number1(int n) {
        int cnt = 0;
        while (n != 0) {
            ++cnt;
            n = (n - 1) & n;
        }
        return cnt;
    }
};

int test(int num1, int num2) {
    Solution solution;
    int ans = solution.minimizeXor(num1, num2);
    std::cout << ans << std::endl;
}

void test1() {
    test(1, 12);
}

void test2() {
    test(12, 1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test2();
    return 0;
}