# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


#head = [0 -> 1 -> 2 -> 3]             
#                  r
#             c  
# None <- 0 <- 
#         ^
#         e
#tail = 3
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head:
            return head

        curr, right = head, head.next
        tail = None

        while curr != None:
            curr.next = tail
            tail = curr
            curr = right
            if right:
                right = right.next

        return tail


        