#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) return nullptr;
        if (head->next->next == nullptr) {
            head->next = nullptr;
            return head;
        }

        ListNode *quick = head;
        ListNode *slow = head;

        ListNode *prev = head;
        while (quick != nullptr && quick->next != nullptr) {
            prev = slow;
            slow = slow->next;
            quick = quick->next->next;
        }

        prev->next = slow->next;
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}