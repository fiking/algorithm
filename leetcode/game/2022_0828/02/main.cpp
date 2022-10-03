#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        vector<bool> flags(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                st.push(i);
                continue;
            }

            int index = st.top();
            st.pop();
            flags[index] = true;
            flags[i] = true;
        }

        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (flags[i]) {
                continue;
            }

            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}