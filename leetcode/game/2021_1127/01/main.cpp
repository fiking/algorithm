#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        if (words1.size() > words2.size()) {
            return countWords(words2, words1);
        }

        int size1 = words1.size();
        vector<int> flag(size1, 0);
        for (int i = 0; i < size1; ++i) {
            if (flag[i] != 0) {
                continue;
            }

            for (int j = i + 1; j < size1; ++j) {
                if (words1[i] == words1[j]) {
                    flag[j] = 1;
                    flag[i] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < size1; ++i) {
            if (flag[i] != 0) {
                continue;
            }

            int cnt = 0;
            for (auto &word2 : words2) {
                if (words1[i] == word2) {
                    ++cnt;
                }

                if (cnt >= 2) {
                    break;
                }
            }

            if (cnt == 1) {
                ++ans;
            }
        }

        return ans;
    }
};

void test1() {
    vector<string> words1 = { "leetcode","is","amazing","as","is" };
    vector<string> words2 = { "amazing","leetcode","is" };
    Solution solution;
    int ans = solution.countWords(words1, words2);
    std::cout << ans << std::endl;
}

void test2() {
    vector<string> words1 = { "b","bb","bbb" };
    vector<string> words2 = { "a","aa","aaa" };
    Solution solution;
    int ans = solution.countWords(words1, words2);
    std::cout << ans << std::endl;
}

void test3() {
    vector<string> words1 = { "a","ab" };
    vector<string> words2 = { "a","a","a","ab" };
    Solution solution;
    int ans = solution.countWords(words1, words2);
    std::cout << ans << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1();
    test2();
    test3();
    return 0;
}