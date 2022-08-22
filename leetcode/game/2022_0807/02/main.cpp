#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<vector<int>> matrix = vector<vector<int>>(100005, vector<int>());
    vector<bool> res = vector<bool>(100005, false);
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for (auto r : restricted) {
            res[r] = true;
        }

        for (auto edge : edges) {
            if (res[edge[0]] || res[edge[1]]) {
                continue;
            }

            matrix[edge[0]].push_back(edge[1]);
            matrix[edge[1]].push_back(edge[0]);
        }

        int ans = 1;
        vector<int> queue;
        queue.push_back(0);
        while (!queue.empty()) {
            int x = queue.front();
            res[x] = true;
            queue.erase(queue.begin());
            for (auto y : matrix[x]) {
                if (res[y]) {
                    continue;
                }
                ++ans;
                queue.push_back(y);
            }
        }
        return ans;
    }
};

void test(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    Solution solu;
    int ans = solu.reachableNodes(n, edges, restricted);
    std::cout << ans << std::endl;
}

void test1() {
    int n = 7;
    vector<vector<int>> edges = { {0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}};
    vector<int> restricted = {4, 5};
    test(n, edges, restricted);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}