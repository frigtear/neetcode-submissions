# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = deque()
        if root:
            queue.append(root)
        result = list()
        while len(queue) > 0:
            temp = deque()
            next_level = list()

            for _ in range(len(queue)):
                node = queue.popleft()
                next_level.append(node.val)
                if node.left:
                    temp.append(node.left)
                if node.right:
                    temp.append(node.right)
                
            
            result.append(next_level)
            queue = temp

        return result

