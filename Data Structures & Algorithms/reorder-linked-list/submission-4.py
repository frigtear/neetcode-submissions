# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        
        slow, fast = head, head

        while fast.next is not None:
            slow = slow.next
            fast = fast.next
            if fast.next:
                fast = fast.next

        tail = None
        while slow is not None:
            temp = slow.next
            slow.next = tail
            tail = slow
            slow = temp

      

        curr = head

        while curr is not None:
            temp = curr.next
            curr.next = tail
            curr = temp
          
            if tail:
                temp = tail.next
                tail.next = curr
                tail = temp

        
      #  return head
            
