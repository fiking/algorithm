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
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans(queries.size(), vector<int>(2, -1));
        for (int i = 0; i < queries.size(); ++i) {
            int cur = queries[i];
            int max = findMax(root, cur);
            int min = findMin(root, cur);
            ans[i] = {max, min};
        }
        return ans;
    }

    int findMax(TreeNode *root, int cur) {
        if (root == nullptr) {
            return -1;
        }

        if (root->val == cur) {
            return root->val;
        }

        if (root->val > cur) {
            return findMax(root->left, cur);
        }

        int next = findMax(root->right, cur);
        return root->val > next ? root->val : next;
    }

    int findMin(TreeNode *root , int cur) {
        if (root == nullptr) {
            return -1;
        }

        if (root->val == cur) {
            return root->val;
        }

        if (root->val < cur) {
            return findMin(root->right, cur);
        }

        int next = findMin(root->left, cur);
        if (next == -1) {
            return root->val;
        }
        return root->val < next ? root->val : next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}