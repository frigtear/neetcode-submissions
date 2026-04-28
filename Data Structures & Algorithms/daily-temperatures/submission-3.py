class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        output = [0 for _ in temperatures]
        stack = list()
     
        for i in range(len(temperatures)):
            temp = temperatures[i]
            
            while stack and stack[-1][0] < temp:
                last_temp = stack.pop(-1)
                output[last_temp[1]] = i - last_temp[1]
            else:
                stack.append((temperatures[i], i))


        for i in range(len(stack)):
            output[stack[i][1]] = 0

        return output


            # [500, 13, 27, 31, 36, 35, 40, 28, 501]
            # [500, 27, ]
            # [50000000, 48, 47, 46, 10000]