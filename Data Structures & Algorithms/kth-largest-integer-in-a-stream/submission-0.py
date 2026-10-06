class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.vals = nums
        self.queue = deque()
        heapq.heapify_max(self.vals)

    def add(self, val: int) -> int:
        heapq.heappush_max(self.vals, val)

        for _ in range(self.k - 1):
            self.queue.append(heapq.heappop_max(self.vals))

        value = self.vals[0]

        while self.queue:
            heapq.heappush_max(self.vals, self.queue.popleft())

        return value