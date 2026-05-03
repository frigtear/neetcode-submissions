class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # so buld graph dict data structure
        
        visited = set()
        graph = dict()

        for edge in edges:
            if edge[0] in graph:
                graph[edge[0]].append(edge[1])
            else:
                graph[edge[0]] = [edge[1]]

            if edge[1] in graph:
                graph[edge[1]].append(edge[0])
            else:
                graph[edge[1]] = [edge[0]]


        def dfs(node, prev):
     #       print(visited, node)
            if node in visited:
               # print(node,"is in visited", visited)
                return False
            else:
                visited.add(node)
            if graph:
                children = graph[node]
            else:
                children = []
           # print(children)
            is_true = True
            for child in children:
                
                if child != prev:
                    print("dfs", child,node)
                    if dfs(child, node) == False:
                        return False
            
            return True
        
        
        result = dfs(0,-1)
      #  print(result)
      #  print(visited)
        return result and len(visited) == n


            
