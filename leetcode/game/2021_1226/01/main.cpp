#include <iostream>

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num / 10 == 0) {
            return true;
        }

        if (num % 10 == 0) {
            return false;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}