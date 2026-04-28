class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        output = [0 for _ in temperatures]
        stack = list()
     
        for i in range(len(temperatures)):
            temp = temperatures[i]
            
            while stack and stack[-1][0] < temp:
                last_temp = stack.pop(-1)
                output[last_temp[1]] = i - last_temp[1]
       
            stack.append((temperatures[i], i))

        return output
