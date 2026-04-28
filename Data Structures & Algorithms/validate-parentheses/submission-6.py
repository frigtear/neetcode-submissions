class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()
        pairs = {
            "[":"]",
            "{":"}",
            "(":")"
        }
        for parenthesis in s:
            if parenthesis in pairs:
                stack.append(parenthesis)
            else:

                if not stack:
                    return False
                    
                last = stack.pop()
          
                if parenthesis != pairs[last]:
                    return False
        
        return len(stack) == 0
                