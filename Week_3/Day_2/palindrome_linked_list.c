#include <stdbool.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

static struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;

    while (head) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next)
        return true;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)
        slow = slow->next;

    struct ListNode* second = reverse(slow);
    struct ListNode* first = head;

    while (second) {
        if (first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}
