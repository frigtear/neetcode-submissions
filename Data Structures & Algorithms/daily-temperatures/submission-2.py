class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result = [0 for _ in temperatures]
        stack = list()
        for i in range(len(temperatures)):
            temp = temperatures[i]
            while stack and stack[-1][0] < temp:
                old_temp = stack.pop()
                result[old_temp[1]] = i - old_temp[1]

            stack.append((temperatures[i], i))

        return result
