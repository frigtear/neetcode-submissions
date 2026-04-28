"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        pointers = {None:None}

        current_node = head
        while current_node:
            copy_of_current = Node(current_node.val)
            pointers[current_node] = copy_of_current
            current_node = current_node.next

        current_node = head
        while current_node:
            copy_of_current = pointers[current_node]
            copy_of_current.next = pointers[current_node.next]
            copy_of_current.random = pointers[current_node.random]
            current_node = current_node.next
        
        return pointers[head]
        

        