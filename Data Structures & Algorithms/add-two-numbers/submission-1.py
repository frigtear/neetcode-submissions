# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
              
# l1=[9,9,9,9,9,9,9]
# l2=[9,9,9,9]
#     8 9 9 9 

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        dummy = curr = ListNode()
        carry = None
        l1_val, l2_val = None, None

        while l1 != None or l2 != None:



            if l1:
                l1_val = l1.val
                l1 = l1.next
            else:
                l1_val = 0

            if l2:
                l2_val = l2.val
                l2 = l2.next
            else:
                l2_val = 0
            
            val = l1_val + l2_val

            if carry:
                val += 1
                carry = None

            if val >= 10:
                carry = 1
                val %= 10
            
            curr.next = ListNode(val=val)
            curr = curr.next

        if carry:
            curr.next = ListNode(val = 1)

        return dummy.next

            


