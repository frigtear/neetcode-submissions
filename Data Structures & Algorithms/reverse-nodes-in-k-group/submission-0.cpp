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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *curr = head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = nullptr;
        ListNode* lastTemp = nullptr;
        
        while (curr != nullptr){

            lastTemp = temp;
            temp = curr;
            ListNode* tail = nullptr;
            ListNode* verify = curr;

            for (int i = 0; i < k; i++) {
                if (verify == nullptr){
                    return dummy.next;
                }
                verify = verify->next;
            }

            for (int i = 0; i < k; i++){
                ListNode* next = curr->next;
                curr->next = tail;
                tail = curr;
                curr = next;
            }

            if (lastTemp != nullptr){
                lastTemp->next = tail;
            }
            else{
                dummy.next = tail;
            }
            temp->next = curr;

        }

        return dummy.next;

    }
};
