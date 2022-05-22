#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(), [&](auto &a, auto &b) {
            return a[0] < a[1];
        });

        int ans = 1;
        vector<vector<int>> rest(stockPrices.size(), vector<int>(2, 0));
        for (int i = 1; i < stockPrices.size(); ++i) {
            rest[i][0]  = stockPrices[i][0] - stockPrices[i - 1][0];
            rest[i][1]  = stockPrices[i][1] - stockPrices[i - 1][1];
            if (i > 2) {
                if (rest[i][0] * rest[i - 1][1] != rest[i - 1][0] * rest[i][1]) {
                    ++ans;
                }
            }

        }

        vector<float> frest(stockPrices.size(), 0.0);
        for (int i = 1; i < stockPrices.size(); ++i) {
            rest[i][0]  = stockPrices[i][0] - stockPrices[i - 1][0];
            rest[i][1]  = stockPrices[i][1] - stockPrices[i - 1][1];
            frest[i] = (float)(rest[i][0]) / rest[i][1];
            if (i > 2) {
                if (frest[i] - frest[i - 1] < 0.00001) {
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