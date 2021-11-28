#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumBuckets(string street) {
        if (street.size() == 1) {
            if (street[0] == '.') {
                return 0;
            } else {
                return -1;
            }
        }

        int size = street.size();
        vector<int> flag(size, -1);
        int ans = 0;
        for (int i = 0; i < size - 2; ) {
            if (street[i] == 'H') {
                if (street[i + 1] == '.' && street[i + 2] == 'H') {
                    ++ans;
                    street[i] = 'X';
                    street[i + 2] = 'X';
                    i = i + 3;
                    continue;
                }
            }
            ++i;
        }

        for (int i = 1; i < size - 1; ++i) {
            if (street[i] == 'H') {
                if (street[i - 1] != '.' && street[i + 1] != '.') {
                    return -1;
                } else {
                    ++ans;
                }
            }
        }

        if (street[0] == 'H') {
            if (street[1] != '.') {
                return -1;
            } else {
                ++ans;
            }
        }

        if (street[size - 1] == 'H') {
            if (street[size - 2] != '.') {
                return -1;
            } else {
                ++ans;
            }
        }
        return ans;
    }
};

void test1() {
    string street = "H..H";
    Solution solution;
    int ans = solution.minimumBuckets(street);
    std::cout << ans << std::endl;
}


void test2() {
    string street = ".H.H.";
    Solution solution;
    int ans = solution.minimumBuckets(street);
    std::cout << ans << std::endl;
}

void test3() {
    string street = ".HHH.";
    Solution solution;
    int ans = solution.minimumBuckets(street);
    std::cout << ans << std::endl;
}

void test4() {
    string street = "H";
    Solution solution;
    int ans = solution.minimumBuckets(street);
    std::cout << ans << std::endl;
}

void test5() {
    string street = ".";
    Solution solution;
    int ans = solution.minimumBuckets(street);
    std::cout << ans << std::endl;
}

void test6() {
    string street = "HH.H";
    Solution solution;
    int ans = solution.minimumBuckets(street);
    std::cout << ans << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}