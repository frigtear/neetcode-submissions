# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(None)
        curr = dummy
        while (list1 or list2):
            print(curr.val)
            if list1 and list2 and min(list1.val, list2.val) == list1.val:
                curr.next = list1
                curr = list1
                list1 = list1.next
                curr.next = None
            elif list1 and list2 and min(list1.val, list2.val) == list2.val:
                curr.next = list2
                curr = list2
                list2 = list2.next
                curr.next = None
            elif list2:
                curr.next = list2
                curr = list2
                list2 = list2.next
                curr.next = None
            elif list1:
                curr.next = list1
                curr = list1
                list1 = list1.next
                curr.next = None
            

        return dummy.next


  


            
            


        