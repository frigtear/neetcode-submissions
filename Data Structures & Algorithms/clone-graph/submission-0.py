"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        
        visited = dict()

        def helper(graph_node):
            if graph_node in visited:
                return visited[graph_node]

            copy = Node(graph_node.val)
            visited[graph_node] = copy

            for neighbor in graph_node.neighbors:
                copy.neighbors.append(helper(neighbor))
            
            return copy

        if node:
            return helper(node)
        else:
            return None
                    

