#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode *p = head;
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        for (int a = 0; a < n; ++a) {
            int lbegin = a;
            int lend = m - a;
            int rbegin = a;
            int rend = n - a;
            for (int i = rbegin; i < rend && p != nullptr; ++i) {
                matrix[lbegin][i] = p->val;
                p = p->next;
            }

            for (int i = lbegin + 1; i < lend && p != nullptr; ++i) {
                matrix[i][rend - 1]  = p->val;
                p = p->next;
            }

            for (int i = rend - 2; i >= rbegin && p != nullptr; --i) {
                matrix[lend -1 ][i] = p->val;
                p = p->next;
            }

            for (int i = lend - 2; i >= lbegin + 1 && p != nullptr; --i) {
                matrix[i][rbegin] = p->val;
                p = p->next;
            }
            if (p == nullptr) {
                break;
            }
        }
        return matrix;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}