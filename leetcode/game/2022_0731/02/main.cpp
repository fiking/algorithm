#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        int len = 1;
        int ans = 1;
        int all = 1;
        while (all < grades.size()) {
            ++len;
            if (all + len <= grades.size()) {
                all += len;
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