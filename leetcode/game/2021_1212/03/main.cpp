#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int currA = capacityA;
        int currB = capacityB;
        int ans = 0;
        for (int i = 0; i < plants.size() / 2; ++i) {
            if (currA < plants[i]) {
                ans++;
                currA = capacityA;
            }

            if (currB < plants[plants.size() - 1 - i]) {
                ans++;
                currB = capacityB;
            }
            currA -= plants[i];
            currB -= plants[plants.size() - 1 - i];
        }

        if (plants.size() % 2 != 0) {
            int index = plants.size() / 2;
            if (currA >= currB) {
                if (currA < plants[index]) {
                    ++ans;
                    return ans;
                }
            } else {
                if (currB < plants[index]) {
                    ++ans;
                    return ans;
                }
            }
        }
        return ans;
    }
};

void test1() {

    vector<int> plants = { 2, 2, 3, 3};
    int capA= 5;
    int capB = 5;
    Solution solution;
    int ans = solution.minimumRefill(plants, capA, capB);
    std::cout << ans << std::endl;
}

void test2() {

    vector<int> plants = { 2, 2, 3, 3};
    int capA= 3;
    int capB = 4;
    Solution solution;
    int ans = solution.minimumRefill(plants, capA, capB);
    std::cout << ans << std::endl;
}

void test3() {
    vector<int> plants = { 5 };
    int capA= 10;
    int capB = 8;
    Solution solution;
    int ans = solution.minimumRefill(plants, capA, capB);
    std::cout << ans << std::endl;
}

void test4() {
    vector<int> plants = { 1, 2, 4, 4, 5 };
    int capA= 6;
    int capB = 5;
    Solution solution;
    int ans = solution.minimumRefill(plants, capA, capB);
    std::cout << ans << std::endl;
}

void test5() {
    vector<int> plants = { 2, 2, 5, 2, 2 };
    int capA= 5;
    int capB = 5;
    Solution solution;
    int ans = solution.minimumRefill(plants, capA, capB);
    std::cout << ans << std::endl;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}