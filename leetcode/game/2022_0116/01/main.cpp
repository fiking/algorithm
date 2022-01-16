#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        size_t len = s.size();
        vector<string> ans;
        for (int i = 0; i < len; i += k) {
            string tmp;
            for (int j = i; j < i + k; ++j) {
                if (j < len) {
                    tmp.push_back(s[j]);
                } else {
                    tmp.push_back(fill);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}