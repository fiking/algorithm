#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> cnt(10, vector<int>(3, 0));
        for (int i = 0; i< rings.size() - 1; i += 2) {
            int index = rings[i + 1] - '0';
            if (rings[i] == 'R') {
                cnt[index][0]++;
            } else if (rings[i] == 'G') {
                cnt[index][1]++;
            } else if (rings[i] == 'B') {
                cnt[index][2]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            if (cnt[i][0] != 0 && cnt[i][1] != 0 && cnt[i][2] != 0) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}