#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    struct Step {
        int pos;
        int time;
    };
public:
    int numberOfWays(int startPos, int endPos, int k) {
        long long ans = 0;
        Step start = { startPos, k };
        queue<Step> work;
        work.push(start);
        while (!work.empty()) {
            Step curr = work.front();
            work.pop();
            std::cout << curr.pos << "  " << curr.time << std::endl;

            if (curr.pos == endPos && curr.time == 0) {
                ++ans;
                continue;
            }

            if (curr.time == 0) {
                continue;
            }

            Step right = { curr.pos + 1, curr.time - 1};
            if ((right.pos < endPos && right.pos + right.time >= endPos) ||
                (right.pos > endPos && endPos + right.time >= right.pos) ||
                (right.pos == endPos)) {
                work.push(right);
            }

            Step left = {curr.pos - 1, curr.time - 1};
            if ((left.pos < endPos && left.pos + left.time >= endPos) ||
                (left.pos > endPos && endPos + left.time >= left.pos) ||
                (left.pos == endPos)) {
                work.push(left);
            }
        }
        return ans % (1000000000 + 7);
    }
};

void test(int start, int end, int k) {
    Solution solu;
    int ans = solu.numberOfWays(start, end, k);
    std::cout << ans << std::endl;
}

void test1() {
    int start = 989;
    int end = 1000;
    int k = 99;
    test(start, end, k);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}
