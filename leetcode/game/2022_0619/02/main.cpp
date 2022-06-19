#include <iostream>

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }

        if (k == 0) {
            if (num % 10 == 0) {
                return 1;
            } else {
                return -1;
            }
        }

        for (int i = 1; ; ++i) {
            int tmp = k * i;
            if (tmp > num) {
                return -1;
            }
            if (tmp % 10 == num % 10) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

2 8
-1