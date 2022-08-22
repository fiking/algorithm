#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> cnts(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            cnts[s[i] - 'a']++;
            if (cnts[s[i] - 'a'] == 2) {
                return s[i];
            }
        }
        return 'a';
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}