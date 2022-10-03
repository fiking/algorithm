#include <iostream>

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0) {
            return n;
        }
        return n * 2;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}