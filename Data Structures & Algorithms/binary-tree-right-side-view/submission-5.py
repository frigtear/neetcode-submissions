# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        queue = deque()
        if root:
            queue.append(root)
        values = list()
        while queue:
            values.append(queue[-1].val)
            q_len = len(queue)
            for i in range(q_len):
                node = queue.popleft()
            
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return values

                

            