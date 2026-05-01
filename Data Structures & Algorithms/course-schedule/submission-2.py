class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        queue = deque()
        graph = {i: [] for i in range(numCourses)}
        indegrees = {i: 0 for i in range(numCourses)}

        for course in prerequisites:
            
            if course[0] not in indegrees:
                indegrees[course[0]] = 1
            else:
                indegrees[course[0]] += 1

            if course[1] not in indegrees:
                indegrees[course[1]] = 0

            if course[1] not in graph:
                graph[course[1]] = [course[0]]
            else:
                graph[course[1]].append(course[0])

        for course_num in range(numCourses):
            if indegrees[course_num] == 0:
                queue.append(course_num)

        print(graph, indegrees, queue)

        nodes_processed = 0

        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                nodes_processed += 1
                if node in graph:
                    children = graph[node]
                    for child in children:
                        indegrees[child] -= 1
                        if indegrees[child] == 0:
                            queue.append(child)
                


      #  print(nodes_processed)
        return nodes_processed == numCourses
       # print(indegrees)
   


        

        