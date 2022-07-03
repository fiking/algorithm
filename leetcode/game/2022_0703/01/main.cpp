#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> table;

        char begin = 'a';
        for (int i = 0; i < key.size(); ++i) {
            if (key[i] == ' ' || table.find(key[i]) != table.end()) {
                continue;
            }

            table[key[i]] = begin;
            ++begin;
        }

        for (int i = 0; i < message.size(); ++i) {
            if (message[i] == ' ') {
                continue;
            }

            message[i] = table[message[i]];
        }
        return message;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}