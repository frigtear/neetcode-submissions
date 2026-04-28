class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()

        pairs = {
            ")":"(",
            "}":"{",
            "]":"["
        }

        for bracket in s:
            if bracket in '({[':
                stack.append(bracket)
            elif not stack:
                return False
            else:
                val = stack.pop()
                if val != pairs[bracket]:
                    return False
            
        return len(stack) == 0