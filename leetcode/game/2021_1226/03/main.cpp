#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> valueToIndex;
        vector<long long > ans(arr.size(), 0);
        for (int i = 0; i < arr.size(); ++i) {
            if (valueToIndex.count(arr[i]) != 0) {
                auto &it = valueToIndex[arr[i]];
                    for (int j = 0; j < it.size(); ++j) {
                        int tmp1 = abs(i - it[j]);
                        ans[i] += tmp1;
                        ans[it[j]] += tmp1;
                    }

            }
            valueToIndex[arr[i]].push_back(i);
        }

        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}