#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), [](auto a, auto b) {
            return a > b;
        });

        int ans = 0;
        for (int i = 0; i < cost.size(); ++i) {
            if (i % 3 == 2) {
                continue;
            }
            ans += cost[i];
        }
        return ans;
    }
};

void test(vector<int> &cost) {
    Solution solu;
    std::cout << solu.minimumCost(cost) << std::endl;
}

void test1() {
    vector<int> cost = {1};
    test(cost);
}

void test2() {
    vector<int> cost = {6,5,7,9,2,2};
    test(cost);
}

void test3() {
    vector<int> cost = {5,5};
    test(cost);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    return 0;
}