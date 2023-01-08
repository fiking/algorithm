#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> maxHeap;

        for (auto n : nums) {
            maxHeap.emplace(n);
        }

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            int max = maxHeap.top();
            maxHeap.pop();
            std::cout << max << std::endl;
            ans += max;

            if (max % 3 != 0) {
                maxHeap.emplace(max / 3 + 1);
            } else {
                maxHeap.emplace(max / 3 );
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}