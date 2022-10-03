#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> nh;
        for (int i = 0; i < names.size(); ++i) {
            nh.push_back(make_pair(names[i], heights[i]));
        }

        sort(nh.begin(), nh.end(), [&](pair<string, int> &a, pair<string, int> &b){
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto n : nh) {
            ans.push_back(n.first);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}