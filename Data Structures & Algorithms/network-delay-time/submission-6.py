class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = dict()

        seen = list()
        distances = defaultdict(lambda: float("inf"))
        distances[k] = 0

        heapq.heapify(seen)
        heapq.heappush(seen, (0, k))

        for time in times:
            if time[0] in graph:
                graph[time[0]].append((time[2], time[1]))
            else:
                graph[time[0]] = [(time[2], time[1])]

        while len(seen) > 0:
            node = heapq.heappop(seen)
            current_distance = node[0]
            current_node = node[1]

            if current_distance > distances[current_node]:
                continue

            if current_node in graph:
                for child in graph[current_node]:

                    child_distance = child[0]
                    child_node = child[1]
                     
                    new_distance = current_distance + child_distance
                   
                    if new_distance < distances[child_node]:
                        distances[child_node] = new_distance
                        heapq.heappush(seen, (new_distance, child_node))
                    
        if len(distances.values()) != n:
            return -1
        else:
            return max(distances.values())
                  


