# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

#q = deque([10, 20, 30])
#print(q.popleft())  # 10
#print(q)            # deque([20, 30])

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        queue = deque()

        if root is not None:
            queue.append(root)
        
        result = list()

        while queue:
 
            result.append(queue[0].val)

            for _ in range(len(queue)):
                
                node = queue.popleft()

                if node.right:
                    queue.append(node.right)
                if node.left:
                    queue.append(node.left)
        
        return result
          

            


