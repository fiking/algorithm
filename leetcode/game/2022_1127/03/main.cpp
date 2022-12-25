#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> work;
        ListNode *p = head;

        while (p != nullptr) {
            while (!work.empty()) {
                auto *top = work.top();
                if (top->val < p->val) {
                    work.pop();
                } else {
                    break;
                }
            }
            work.push(p);
            p = p->next;
        }

        ListNode *ans = nullptr;
        while (!work.empty()) {
            auto *top = work.top();
            work.pop();
            top->next = ans;
            ans = top;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}