#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long ans = 0;
        int sum = skill[0] + skill[skill.size() - 1];
        for (int i = 0, e = skill.size() / 2; i < e; ++i) {
            int tmp = skill[i] + skill[skill.size() - i - 1];
            if (tmp != sum) {
                return -1;
            }
            ans += skill[i] * skill[skill.size() - i - 1];
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}