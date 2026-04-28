class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
      #  temperatures = [30,38, 30, 36,35,40,28]
      #                                    ^  
      # stack -> 1,  5,    
      # 1 - 0
      # 36
      # [1, 4, 1, 2, 0, 0, 0, 0]
      # [1, ]
      # result -> 1,
        
        result, stack = [0,]*len(temperatures), list()
        for i in range(len(temperatures)):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                result[stack.pop()] = i - stack[-1]
            stack.append(i)
        return result

    

