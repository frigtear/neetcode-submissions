# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        def helper(node, largest):
            if node:
                num = 0

                if node.val >= largest:
                    num = 1
                    largest = node.val
                 
                return num + helper(node.left, largest) + helper(node.right, largest)
            else:
                return 0

        return helper(root, root.val)
