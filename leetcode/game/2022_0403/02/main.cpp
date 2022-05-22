#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> players;
        unordered_map<int, unordered_set<int>> loses;
         for (auto &match : matches) {
             players.insert(match[0]);
             players.insert(match[1]);
             loses[match[1]].insert(match[0]);
         }

         vector<vector<int>> ans(2, vector<int>());
         for (auto & player : players) {
             auto it = loses.find(player);
             if (it == loses.end()) {
                 ans[0].push_back(player);
             } else if (it->second.size() == 1) {
                 ans[1].push_back(player);
             }
         }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}