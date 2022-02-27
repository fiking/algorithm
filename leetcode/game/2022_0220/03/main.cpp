#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> charCnt;
        map<char, int> charRep;
        for (int i = 0; i < s.size(); ++i) {
            charCnt[s[i]]++;
            charRep[s[i]] = 0;
        }

        string ans;
        bool rep = true;
        while (rep) {
            rep = false;
            for (auto it = charCnt.rbegin(); it != charCnt.rend(); it++) {
                if (it->second == 0) {
                    continue;
                }

                if (it->first != ans.back()) {
                    charRep[ans.back()] = 0;
                    ans.push_back(it->first);
                    charRep[it->first] = 1;
                    charCnt[it->first]--;
                    rep = true;
                    break;
                } else {
                    if (charRep[it->first] + 1 > repeatLimit) {
                        continue;
                    }

                    ans.push_back(it->first);
                    charRep[it->first] += 1;
                    charCnt[it->first]--;
                    rep = true;
                    break;
                }
            }
        }
        return ans;
    }
};

void test() {
    string s = "cczazcc";
    int repeat = 3;
    Solution solu;
    std::cout << solu.repeatLimitedString(s, repeat) << std::endl;
}

void test1() {
    string s = "aababab";
    int repeat = 2;
    Solution solu;
    std::cout << solu.repeatLimitedString(s, repeat) << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test();
    test1();
    return 0;
}