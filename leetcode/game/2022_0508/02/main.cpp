#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

class Solution {
    int ans = 0;
public:
    int averageOfSubtree(TreeNode* root) {
        (void)dfs(root);
        return ans;
    }

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return pair<int, int>(0, 0);
        }

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int sum = root->val + left.first + right.first;
        int cnt = 1 + left.second + right.second;
        if (sum / cnt == root->val) {
            ++ans;
        }
        return pair<int, int>(sum, cnt);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}