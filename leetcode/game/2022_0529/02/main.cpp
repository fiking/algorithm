#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int dollar = -1;
        int dollar_i = 0;
        string ans;

        int tmp = 0;
        map<int, pair<int, string>> moneys;

        for (int i = 0; i < sentence.size(); ++i) {
            switch (sentence[i]) {
                case '$':{
                    dollar += 1;
                    dollar_i = i;
                    break;
                }

                case '0'...'9': {
                    if (dollar == 1) {
                        tmp = tmp*10 + (sentence[i] - 'a');
                    }
                    break;
                }

                case ' ': {
                    if (dollar == 1) {
                        string s;

                    }

                    dollar = -1;
                    tmp = 0;
                    dollar_i = 0;
                }


            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}