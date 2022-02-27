#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (pref.size() > words[i].size()) {
                continue;
            }
            bool flag = true;
            for (int j = 0; j < pref.size(); ++j) {
                if (pref[j] != words[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
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