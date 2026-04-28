# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow, fast = head, head

        while fast is not None and fast.next is not None:
            fast = fast.next
            fast = fast.next
            slow = slow.next

        # Slow points to midpoint

        curr = slow
        tail = None
        while curr is not None:
     
            temp = curr.next
            curr.next = tail
            tail = curr
            curr = temp

        left = head
        right = curr
        dummy = ListNode()
        curr = dummy
        i = 0
     
        left = head
        right = tail

        while right.next is not None: 
            left_next = left.next
            right_next = right.next

            left.next = right
            right.next = left_next

            left = left_next
            right = right_next
            
        
                


    

        

        