#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        int curEnergy = initialEnergy;
        int curExperience = initialExperience;
        for (int i = 0; i < energy.size();) {
            if (curEnergy > energy[i] && curExperience > experience[i]) {
                curEnergy -= energy[i];
                curExperience += experience[i];
                ++i;
                continue;
            }

            if (curEnergy <= energy[i]) {
                ans += energy[i] - curEnergy + 1;
                curEnergy = energy[i] + 1;
            }

            if (curExperience <= experience[i]) {
                ans += experience[i] - curExperience + 1;
                curExperience = experience[i] + 1;
            }
        }
        return ans;
    }
};

int test(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
    Solution solu;
    int ans = solu.minNumberOfHours(initialEnergy, initialExperience, energy, experience);
    std::cout << ans << std::endl;
    return 0;
}

void test1() {
    int initialEnergy = 5;
    int initialExp = 3;

    vector<int> energy = { 1, 4, 3, 2 };
    vector<int> exp = { 2, 6, 3, 1};
    test(initialEnergy, initialExp, energy, exp);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}