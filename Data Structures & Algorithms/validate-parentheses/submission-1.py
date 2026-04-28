class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()
        pairs = {
            "(":")",
            "[":"]",
            "{":"}",
        }

    #  s = "([{}])"
    #          ^
    #  stack ->       ( [ {  
        for bracket in s:
            if bracket in pairs:
                stack.append(bracket)
            elif (not stack and bracket not in pairs) or (bracket != pairs[stack[-1]]):
                return False
            else:
                del stack[-1]
        return len(stack) == 0


            
        