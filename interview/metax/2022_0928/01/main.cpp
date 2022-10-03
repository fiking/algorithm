// 给定一个链表，分段反转链表，形成新的链表

#include <iostream>
#include <stack>

using namespace std;

class List {
public:
    int value;
    List *next;
};

List *Revert(List *list, int k) {
    stack<List *> aux;
    List *p = list;
    List *ans = nullptr;
    int cnt = 0;
    while (p != nullptr) {
        if (cnt < k) {
            aux.push(p);
            p = p->next;
        } else {
            while (!aux.empty()) {
                List *cur = aux.top();
                aux.pop();
                if (ans == nullptr) {
                    ans = cur;
                } else {
                    ans->next = cur;
                    cur->next = nullptr;
                }
            }
            cnt = 0;
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}