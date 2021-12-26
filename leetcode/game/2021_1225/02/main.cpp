#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int old = supplies.size();
        int newSize = old;

        unordered_set<int> finish;
        unordered_set<string> sups;
        vector<string> ans;
        for (int i = 0; i < supplies.size(); ++i) {
            sups.insert(supplies[i]);
        }

        do {
            old = newSize;
            for (int i = 0; i < recipes.size(); ++i) {
                if (finish.count(i) != 0) {
                    continue;
                }

                int j = 0;
                for (; j < ingredients[i].size(); ++j) {
                    if (sups.count(ingredients[i][j]) == 0) {
                        break;
                    }
                }
                if (j < ingredients[i].size()) {
                    continue;
                }

                ans.push_back(recipes[i]);
                sups.insert(recipes[i]);
                finish.insert(i);
                newSize++;
            }
        } while (newSize != old);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}