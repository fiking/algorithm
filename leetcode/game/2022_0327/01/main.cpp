#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> same;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    same.insert(nums1[i]);
                }
            }
        }

        vector<vector<int>> ans(2, vector<int>());
        for (int i = 0; i < nums1.size(); ++i) {
            if (same.find(nums1[i]) == same.end()) {
                int j = 0;
                for (j = 0; j < ans[0].size(); ++j) {
                    if (ans[0][j] == nums1[i]) {
                        break;
                    }
                }
                if (j == ans[0].size()) {
                    ans[0].push_back(nums1[i]);
                }
            }
        }

        for (int i = 0; i < nums2.size(); ++i) {
            if (same.find(nums2[i]) == same.end()) {
                int j = 0;
                for (j = 0; j < ans[1].size(); ++j) {
                    if (ans[1][j] == nums2[i]) {
                        break;
                    }
                }
                if (j == ans[1].size()) {
                    ans[1].push_back(nums2[i]);
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