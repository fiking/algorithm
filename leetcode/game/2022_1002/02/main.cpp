#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();

        int max = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int tmp = 0;
                for (int y = j; y < j + 3; ++y) {
                    tmp += grid[i][y];
                }
                tmp += grid[i + 1][j + 1];
                for (int y = j; y < j + 3; ++y) {
                    tmp += grid[i + 2][y];
                }
                if (max < tmp) {
                    max = tmp;
                }
            }
        }
        return max;
    }
};

void test(vector<vector<int>> &grid) {
    Solution solu;
    int ans = solu.maxSum(grid);
    std::cout << ans << std::endl;
    return;
}

void test1() {
    vector<vector<int>> grid = { {6,2,1,3}, {4,2,1,5}, {9,2,8,7}, {4,1,2,9}};
    test(grid);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}