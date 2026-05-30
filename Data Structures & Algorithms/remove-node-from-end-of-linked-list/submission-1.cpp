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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* prev = nullptr;
        ListNode* fast = head;
        int i = 1;
        while (fast != nullptr && fast->next != nullptr) {
            if (i >= n) {
                prev = slow;
                slow = slow->next;
            }
            fast = fast->next;
            ++i;
        }
        if (prev != nullptr) {
            prev->next = slow->next;
        } else {
            return slow->next;
        }
        
        return head;
    }
};
