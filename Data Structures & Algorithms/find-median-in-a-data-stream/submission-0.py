class MedianFinder:

    def __init__(self):
        self.numbers = list()
        self.length = 0

    def addNum(self, num: int) -> None:
        heapq.heappush(self.numbers, num)
        self.length = self.length + 1


    def findMedian(self) -> float:
        temp = list()
        # Grab middle element of heap and put middle elements back
        middle_element_index = (self.length - 1) // 2 
     
      # print(middle_element_index)
        for _ in range(middle_element_index):
            temp.append(heapq.heappop(self.numbers))

        if self.length % 2 == 1:
            median = heapq.heappop(self.numbers)
            temp.append(median)
        else:
            middle_left = heapq.heappop(self.numbers)
            middle_right = heapq.heappop(self.numbers)
            median = (middle_left + middle_right) / 2 
            temp.append(middle_left)
            temp.append(middle_right)
        
        for value in temp:
            heapq.heappush(self.numbers, value)

        return median

      



        
        