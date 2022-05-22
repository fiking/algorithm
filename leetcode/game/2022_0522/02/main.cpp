#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        auto size = capacity.size();
        vector<int> rest(size, 0);
        for (auto i = 0; i < size; ++i) {
            rest[i] = capacity[i] - rocks[i];
        }
        sort(rest.begin(), rest.end());
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += rest[i];
            if (sum <= additionalRocks) {
                ++ans;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}