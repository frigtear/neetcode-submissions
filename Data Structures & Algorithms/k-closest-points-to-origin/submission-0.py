import math

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        def calculate_distance(x, y):
            return math.sqrt(x**2 + y**2)

        heap = [(calculate_distance(point[0], point[1]), point[0], point[1]) for point in points]
        heapq.heapify(heap)
        smallest = heapq.nsmallest(k, heap)
        return [[point[1], point[2]] for point in smallest]




        