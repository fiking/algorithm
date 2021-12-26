#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            int step = 0;
            int x = startPos[0];
            int y = startPos[1];
            for (int j = i; j < s.size(); ++j) {
                if (s[j] == 'R') {
                    if (y + 1 < n) {
                        y = y + 1;
                        ++step;
                        continue;
                    }
                } else if (s[j] == 'L') {
                    if (y - 1 >= 0) {
                        --y;
                        ++step;
                        continue;
                    }
                } else if (s[j] == 'U') {
                    if (x - 1 >= 0) {
                        --x;
                        ++step;
                        continue;
                    }
                } else if (s[j] == 'D') {
                    if (x + 1 < n) {
                        ++x;
                        ++step;
                        continue;
                    }
                }
                break;
            }
            ans.push_back(step);
        }

        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}