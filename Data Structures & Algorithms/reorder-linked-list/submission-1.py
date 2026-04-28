
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = None
        curr = slow

        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        left, right = head, prev
        
        while left and right:
            tempL = left.next
            tempR = right.next
            left.next = right
            right.next = tempL
            left = tempL
            right = tempR

        if left:
            left.next = None
      


              

            
            


        



        