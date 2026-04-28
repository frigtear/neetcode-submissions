from collections import deque
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        pairs = list()
        stack = list()
        def helper(parenth : str, n : int, stack) -> str:
            print(parenth, stack)
            if n == 0 and not stack:
                pairs.append(parenth)

            if n > 0:
                temp = stack[:]
                temp.append("(")
                helper(parenth + "(", n - 1, temp)

            if stack:
                print("if stack called")
                temp = stack[:]
                temp.pop()
                helper(parenth + ")", n, temp)
            else:
                print("if stack false", stack)

        helper("", n, stack)
        return pairs



