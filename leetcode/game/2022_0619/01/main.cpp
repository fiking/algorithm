#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        char ans;
        for (ans = 'Z'; ans >= 'A'; --ans) {
            int flag = 0;
            int lflag = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == ans) {
                    flag = 1;
                }

                if (s[i] < 'a' || s[i] > 'z') {
                    continue;
                }

                if (s[i] - 'a' == ans - 'A') {
                    lflag = 1;
                }

                if (flag == 1 && lflag == 1) {
                    break;
                }
            }
            if (flag == 1 && lflag == 1) {
                string aaa;
                aaa.push_back(ans);
                return aaa;
            }
        }
        return "";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
