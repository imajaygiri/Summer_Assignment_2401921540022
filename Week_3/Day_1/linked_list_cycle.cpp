#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

bool hasCycle(ListNode* head) {
    std::unordered_map<ListNode*, ListNode*> mp;
    ListNode* temp = head;
    while (temp != nullptr) {
        auto it = mp.find(temp);
        if (it == mp.end()) {
            mp[temp] = temp;
        } else {
            if (it->second == temp) {
                return true;
            }
        }
        temp = temp->next;
    }
    return false;
}
