class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        inverted = [-stone for stone in stones]
        heapq.heapify(inverted)
        while len(inverted) > 1:
            rock1 = -heapq.heappop(inverted)
            rock2 = -heapq.heappop(inverted)
            if rock1 < rock2:
                rock2 -= rock1
                heapq.heappush(inverted, -rock2)
            elif rock2 < rock1:
                rock1 -= rock2
                heapq.heappush(inverted, -rock1)
        if len(inverted) == 0:
            return 0
        return -heapq.heappop(inverted)

        