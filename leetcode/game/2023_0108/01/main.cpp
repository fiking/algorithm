#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for (auto n : nums) {
            if (n < 0) neg++;
            else if (n > 0) pos++;
        }
        return pos > neg ? pos : neg;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}