#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                int k = 0;
                for (k = 0; k < grid.size(); ++k) {
                    if (grid[i][k] != grid[k][j]) {
                        break;
                    }
                }
                if (k >= grid.size()) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}