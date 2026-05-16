class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(list)
        distances = defaultdict(lambda : float("inf"))
        seen = list()
        heapq.heappush(seen, (0,k))
        distances[k] = 0
        for time in times:
            graph[time[0]].append((time[2], time[1]))

        while seen:
            node = heapq.heappop(seen)
        
            distance = node[0]
            target = node[1]

            if distances[target] < distance:
                continue 

            children = graph[target]
        #    print(children)
         #   print(distance, target)
            for child in children:
                child_distance = child[0]
                child_target = child[1]

                new_distance = child_distance + distance

                if new_distance < distances[child_target]:
                    distances[child_target] = new_distance
                    heapq.heappush(seen, (new_distance, child_target))

       # print(distances)
        if len(distances.values()) < n:
            return -1
        else:
            return max(distances.values())


        

