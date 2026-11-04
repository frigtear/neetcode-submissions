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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Input: l1 = [1,2,3]
         //.           [4,5,6]
         //             5, 7, 9
         //          l1 = [9, 2], l2 = 
         //               [9, 3]
         //                8  6

        ListNode* left = l1;
        ListNode* right = l2;
        int curr_sum = 0;
        int carry = 0;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (left != nullptr || right != nullptr){
            int curr_sum = 0;
    
            if (left != nullptr){
                curr_sum += left->val;
            }
            if (right != nullptr){
                curr_sum += right->val;
            }

            curr_sum += carry;
            carry = 0;

            if (curr_sum >= 10){
                carry = 1;
                curr_sum -= 10;
            }

            ListNode* sum_node = new ListNode(curr_sum);
            curr->next = sum_node;
            curr = curr->next;

            if (left != nullptr){
                left = left->next;
            }
            if (right != nullptr){
                right = right->next;
            }
        }

        if (carry == 1){
            curr->next = new ListNode(1);
        }

        return dummy->next;

    }
};
