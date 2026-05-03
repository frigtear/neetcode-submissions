class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = dict()
        visited = set()

        for edge in edges:
            if edge[0] in graph:
                graph[edge[0]].append(edge[1])
            else:
                graph[edge[0]] = [edge[1]]

            if edge[1] in graph:
                graph[edge[1]].append(edge[0])
            else:
                graph[edge[1]] = [edge[0]]

        def dfs(node):

            if node in visited:
                return

            if node in graph:
                connections = graph[node]
            else:
                connections = []

            visited.add(node)

            for connection in connections:
                dfs(connection)

        islands = 0
        for i in range(n):
            if i not in visited:
                islands += 1
                dfs(i)

        return islands

            