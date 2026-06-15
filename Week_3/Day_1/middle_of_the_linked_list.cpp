#include <cstddef>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode* next) : val(x), next(next) {
    }
};
ListNode* middleNode(ListNode* head) {
    int size = 0;
    ListNode* temp = head;

    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    int mid = size / 2;
    ListNode* tmp = head;
    for (int i = 0; i < mid; i++) {
        tmp = tmp->next;
    }
    return tmp;
}
