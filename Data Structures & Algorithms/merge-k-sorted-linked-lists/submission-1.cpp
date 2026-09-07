#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode dummy(0);
        ListNode* curr = &dummy; 
        
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (const auto &node : lists){
            if (node != nullptr){
                pq.push(node);
            }
        }

        while (!pq.empty()){

            ListNode* node = pq.top();
            pq.pop();

            if (node->next != nullptr){
                pq.push(node->next);
            }

            curr->next = node;
            curr = node;
        }

        return dummy.next;
    }
};
