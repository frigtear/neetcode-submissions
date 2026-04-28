# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = list()
        if not root:
            return []
        seen_queue = deque([root])
        while seen_queue:
            level_size = len(seen_queue)
            level = list()

            for _ in range(level_size):
                node_to_visit = seen_queue.popleft()
                level.append(node_to_visit.val)
                if node_to_visit.left:
                    seen_queue.append(node_to_visit.left)
                if node_to_visit.right:
                    seen_queue.append(node_to_visit.right)

            result.append(level)

        return result






        

