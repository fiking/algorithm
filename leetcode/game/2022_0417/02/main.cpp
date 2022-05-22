#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> taskmaps;
        for (int i = 0; i < tasks.size(); ++i) {
            taskmaps[tasks[i]]++;
        }

        int ans = 0;
        for (auto &task : taskmaps) {
            if (task.second < 2) {
                return -1;
            }

            ans += task.second / 3;
            int tmp = task.second % 3;
            if (tmp == 2 || tmp == 1) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}