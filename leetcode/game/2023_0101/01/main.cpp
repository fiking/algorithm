#include <iostream>

class Solution {
public:
    int countDigits(int num) {
        int a = num;
        int ans = 0;
        while (a != 0) {
            int tmp = a % 10;
            a = a / 10;
            if (num % tmp == 0)
                ++ans;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}