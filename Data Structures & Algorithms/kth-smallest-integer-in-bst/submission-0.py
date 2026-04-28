# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:

        def get_num_nodes(node):
            if node:
                num_nodes = 1 + get_num_nodes(node.left) + get_num_nodes(node.right)
                return num_nodes
            else:
                return 0

        left_num_nodes = 0
        right_num_nodes = 0



        if root.left:
            left_num_nodes = get_num_nodes(root.left)
        if root.right:
            right_num_nodes = get_num_nodes(root.right)

        if k > left_num_nodes + 1:
            return self.kthSmallest(root.right , k - (left_num_nodes + 1))
        elif k == left_num_nodes + 1:
            return root.val
        else:
            return self.kthSmallest(root.left, k)
  


        


        