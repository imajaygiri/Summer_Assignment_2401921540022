#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1,
                               struct ListNode* list2) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* temp = dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (!list1) {
        temp->next = list2;
    }

    if (!list2) {
        temp->next = list1;
    }
    struct ListNode* head = dummy->next;
    free(dummy);
    return head;
}
