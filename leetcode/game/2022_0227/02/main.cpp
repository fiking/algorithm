#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s_cnt(26, 0);
        vector<int> t_cnt(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            s_cnt[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); ++i) {
            t_cnt[t[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (s_cnt[i] > t_cnt[i]) {
                ans += s_cnt[i] - t_cnt[i];
            } else {
                ans += t_cnt[i] - s_cnt[i];
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}