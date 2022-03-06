#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        ans[1] = 1;
//        ans[2] = 2;
        for (int i = 2; i <= n; ++i) {
            int sum = 0;
            for (int x = 0; x < i / 2; ++x) {
                sum += ans[x] * ans[i - x - 1];
            }
            sum *= 2;
            if (i % 2 != 0) {
                sum += ans[i / 2] * ans[i / 2];
            }
            ans[i] = sum;
        }
        return ans[n];
    }
};

void test(int n) {
    Solution solu;
    int ans = solu.numTrees(n);
    std::cout << ans << std::endl;
}

void test1() {
    int n = 5;
    test(n);
}

void test2() {
    int n = 1;
    test(n);
}

void test3() {
    int n = 4;
    test(n);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
//    test2();
//    test3();
    return 0;
}