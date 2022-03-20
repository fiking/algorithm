#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        int same = 0;
        for (int i = 0; i < directions.size(); ++i) {
            if (directions[i] == 'L') {
                if (same != 0) {
                    ans += same + 1;
                    same = 0;
                    directions[i] = 'S';
                }
                continue;
            }

            if (directions[i] == 'R') {
                same++;
                continue;
            }

            if (directions[i] == 'S') {
                if (same != 0) {
                    ans += same;
                    same = 0;
                }
                continue;
            }
        }

        same = 0;
        for (int i = directions.size() - 1; i >= 0; --i) {
            if (directions[i] == 'R') {
                if (same != 0) {
                    ans += same + 1;
                    same = 0;
                    directions[i] = 'S';
                }
                continue;
            }

            if (directions[i] == 'L') {
                same++;
                continue;
            }

            if (directions[i] == 'S') {
                if (same != 0) {
                    ans += same;
                    same = 0;
                }
                continue;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}