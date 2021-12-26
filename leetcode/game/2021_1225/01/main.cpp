#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for (int i = 0; i < sentences.size(); ++i) {
            int tmp = 0;
            for (int j = 0; j < sentences[i].size(); ++j) {
                if (sentences[i][j] == ' ') {
                    ++tmp;
                }
            }
            if (tmp > ans) {
                ans = tmp;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}