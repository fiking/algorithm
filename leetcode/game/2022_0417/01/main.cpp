#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
//        std::cout << s.length() << std::endl;
        while (s.length() > k) {
            string ans;
            for (int i = 0; i < s.length(); i += k) {
                int val = 0;
                for (int j = i; j < i + k && j < s.length(); ++j) {
                    val += s[j] - '0';
                }
                ans += to_string(val);

//                std::cout << val << std::endl;
            }
            s = ans;
        }
        return s;
    }
};

void test(string s, int k) {
    Solution solu;
    std::cout << solu.digitSum(s, k) << std::endl;
}

void test1() {
    string s = "11111222223";
    int k = 3;
    test(s, k);
}

void test2() {
    string s = "11";
    int k = 3;
    test(s, k);
}

void test3() {
    string s = "00000000";
    int k = 3;
    test(s, k);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    return 0;
}