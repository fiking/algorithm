#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<vector<int>> nums(words.size(), vector<int>(26, 0));
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                nums[i][words[i][j] - 'a'] = 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                int k = 0;
                for (; k < 26; ++k) {
                    if (nums[i][k] != nums[j][k]) {
                        break;
                    }
                }
                if (k >= 26) ++ans;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}