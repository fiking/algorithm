#include <iostream>

/**
 * Definition for singly-linked list.
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *cnt = head;
        ListNode *prevcnt = nullptr;
        while (cnt->next != nullptr) {
            ListNode *next = cnt->next;
            if (next->val != 0) {
                cnt->val += next->val;
                cnt->next = next->next;
            } else {
                prevcnt = cnt;
                cnt = cnt->next;
            }
        }
        prevcnt->next = nullptr;
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}