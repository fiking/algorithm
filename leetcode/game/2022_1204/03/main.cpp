#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_map<int, int>> rds;
        for (auto road : roads) {
            rds[road[0]][road[1]] = road[2];
            rds[road[1]][road[0]] = road[2];
        }

        queue<int> work;
        work.push(1);
        int ans = 1000000;
        vector<vector<bool>> flag(100001, vector<bool>(100001, false));
        while (!work.empty()) {
            int cur = work.front();
            work.pop();

            for (auto it = rds[cur].begin(), e = rds[cur].end(); it != e; ++it) {
                if (flag[cur][it->first]) continue;

                work.push(it->first);
                if (it->second < ans)
                    ans = it->second;
                flag[cur][it->first] = true;
            }
        }
        return ans;
    }
};

void test(int n, vector<vector<int>>& roads) {
    Solution sl;
    std::cout << sl.minScore(n, roads) << std::endl;
}

void test1() {
    int n = 6;
    vector<vector<int>> roads = {
            {4,5,7468},
            {6,2,7173},
            {6,3,8365},
            {2,3,7674},
            {5,6,7852},
            {1,2,8547},
            {2,4,1885},
            {2,5,5192},
            {1,3,4065},
            {1,4,7357}
    };
    test(n, roads);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}

14
[[2,9,2308],[2,5,2150],[12,3,4944],[13,5,5462],[2,10,2187],[2,12,8132],[2,13,3666],[4,14,3019],[2,4,6759],[2,14,9869],[1,10,8147],[3,4,7971],[9,13,8026],[5,12,9982],[10,9,6459]]