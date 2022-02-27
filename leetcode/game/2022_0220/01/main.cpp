#include <iostream>

using namespace std;

class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 2; i <= num; ++i) {
            int bitCnt = 0;
            int a = i;
            while (a != 0) {
                bitCnt += a % 10;
                a = a / 10;
            }
            if (bitCnt % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}