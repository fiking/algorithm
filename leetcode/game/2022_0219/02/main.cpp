#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if (num % 3 == 0) {
            long long a = num / 3;
            ans.push_back(a - 1);
            ans.push_back(a);
            ans.push_back(a + 1);
        }
        return ans;
    }
};

void test() {
    long long value = 6675975537;
    Solution solu;
    vector<long long> ans = solu.sumOfThree(value);
    for (auto a : ans) {
        std::cout << a << " ";
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test();
    return 0;
}