#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        int min = a > b ? b : a;
        for (int i = 1; i < min; ++i) {
            if (a % i == 0 && b % i == 0) {
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