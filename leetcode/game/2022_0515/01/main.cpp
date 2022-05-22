#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string> &words) {
        vector<bool> flags(words.size(), true);
        int start = 0;
        for (int i = start + 1; i < words.size(); ++i) {
            if (same(words[start], words[i])) {
                flags[i] = false;
            } else {
                start = i;
            }
        }

        vector<string> ans;
        for (int i = 0; i < flags.size(); ++i) {
            if (flags[i]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }

    bool same(string a, string b) {
        vector<int> aa(26, 0);
        for (int i = 0; i < a.size(); ++i) {
            aa[a[i] - 'a']++;
        }
        for (int i = 0; i < b.size(); ++i) {
            aa[b[i] - 'a']--;
        }

        for (auto &v : aa) {
            if (v != 0) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}