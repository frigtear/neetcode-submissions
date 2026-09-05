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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);

        ListNode* l = &dummy;
        for (int i = 1; i < left; i++) {
            l = l->next;
        }

        ListNode* r = &dummy;
        for (int i = 0; i < right; i++) {
            r = r->next;
        }

        ListNode* temp = r->next;

        ListNode* curr = l->next;
        ListNode* end = curr;

        ListNode* tail = nullptr;

        while (curr != temp) {
            ListNode* next = curr->next;

            curr->next = tail;
            tail = curr;

            curr = next;
        }

        l->next = tail;
        end->next = temp;

        return dummy.next;
    }
};