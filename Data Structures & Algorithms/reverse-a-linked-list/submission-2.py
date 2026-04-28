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
            return None

        tail, temp, curr, = None, None, head
        while curr is not None:
            temp = curr.next
            curr.next = tail 
            tail = curr
            curr = temp

        return tail