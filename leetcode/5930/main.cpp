#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        map<int, int> mins;
        map<int, int> maxs;
        for (int i = 0; i < colors.size(); ++i) {
            if (maxs.count(colors[i]) != 0) {
                maxs[colors[i]] = i;
            } else {
                mins[colors[i]] = i;
                maxs[colors[i]] = i;
            }
        }

        int ans = 0;
        for (auto &max : maxs) {
            for (auto &min : mins) {
                if (max.first != min.first) {
                    if (max.second - min.second > ans) {
                        ans = max.second - min.second;
                    }
                }
            }
        }
        return ans;
    }
};

void test() {
    vector<int> colors = { 1,1,1,6,1,1,1 };
    Solution solution;
    int ans = solution.maxDistance(colors);
    std::cout << ans << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test();
    return 0;
}