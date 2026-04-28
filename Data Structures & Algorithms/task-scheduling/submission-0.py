class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        values = dict()
        queue = collections.deque()

        # step 1: count tasks
        for task in tasks:
            if task in values:
                values[task] += 1
            else:
                values[task] = 1
        
        counted_tasks = [-value for value in list(values.values())]
        heapq.heapify(counted_tasks)
        time = 0

        while counted_tasks or queue:
            time += 1
            print(time, counted_tasks, queue)
           
            if queue and queue[0][1] == time:
                heapq.heappush(counted_tasks, queue.popleft()[0])
            
            if counted_tasks:
                task = heapq.heappop(counted_tasks) + 1
                if task < 0:
                    queue.append((task, time + n + 1))

        return time

            
        



           


            

