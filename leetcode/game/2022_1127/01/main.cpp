#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; ++i) {
            int left = 0;
            int right = 0;
            for (int a = 1; a <= i; ++a) {
                left += a;
            }
            for (int b = i; b <= n; ++b) {
                right += b;
            }

            if (left == right) {
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