#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

// n = 2
// dummy -> 1 -> 2 -> 3 -> 4d -> 5

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* temp = slow->next;
    slow->next = temp->next;
    free(temp);
    return dummy.next;
}
