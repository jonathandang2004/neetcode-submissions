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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // initialise head + tail
        if (list1->val <= list2->val) {
            head = tail = list1;
            list1 = list1->next;
        } else {
            head = tail = list2;
            list2 = list2->next;
        }

        // merge normally
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // attach remaining part
        tail->next = (list1 ? list1 : list2);
        // ListNode* head = (list1->val < list2->val) ? list1 : list2;
        // ListNode* cur1 = list1;
        // ListNode* prev1 = nullptr;
        // ListNode* cur2 = list2;
        // ListNode* prev2 = nullptr;
        // while (cur1 != nullptr && cur2 != nullptr) {
        //     if (cur1->val < cur2->val) {
        //         while (cur1 != nullptr && cur1->val < cur2->val) {
        //             prev1 = cur1;
        //             cur1 = cur1->next;
        //         }
        //         prev1->next = cur2;
        //     } else {
        //         while (cur1 != nullptr && cur1->val >= cur2->val) {
        //             prev2 = cur2;
        //             cur2 = cur2->next;
        //         }
        //         prev2->next = cur1;
        //     }
        // }

        return head;
    }
};
