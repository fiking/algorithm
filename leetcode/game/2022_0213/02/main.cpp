#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> odd;
        for (int i = 0; i < nums.size(); i += 2) {
            odd[nums[i]]++;
        }
        

        map<int, int> even;
        for (int i = 1; i < nums.size(); i += 2) {
            even[nums[i]]++;
        }


    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}