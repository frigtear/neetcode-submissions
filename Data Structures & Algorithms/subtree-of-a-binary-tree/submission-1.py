# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def isSameTree(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
            if not p and q:
                return False
            elif not q and p:
                return False
            elif not q and not p:
                return True
            else:
                return p.val == q.val and isSameTree(p.left, q.left) and isSameTree(p.right, q.right)

        queue = deque([root])
        while queue:
            node = queue.popleft()
            if isSameTree(node, subRoot):
                return True
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        return False
            
        

            