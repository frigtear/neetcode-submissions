# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        dummy = ListNode()
        curr = dummy
     
        while list1 and list2:

            if list1.val <= list2.val:
                smaller = list1
                list1 = list1.next
            else:
                smaller = list2
                list2 = list2.next

            curr.next = smaller
            curr = smaller

        if list1:
            curr.next = list1

        if list2:
            curr.next = list2

        return dummy.next
            

            

            


            