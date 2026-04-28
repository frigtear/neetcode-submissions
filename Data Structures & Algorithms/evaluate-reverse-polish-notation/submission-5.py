from collections import deque
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # tokens = ["1","2","+","3","*","4","-"]
        #                            ^ 
        # stack -> 3 
        # curr -> 3

        stack = deque()
        for token in tokens:
         #   print(stack, curr, token)
            if token not in "+*-/":
                stack.append(int(token))
            else:
                print(stack, token)
                a, b = stack.pop(), stack.pop()
                if token == "+":
                    stack.append(a + b)
                if token == "/":
                    stack.append(int(b / a))
                if token == "-":
                    stack.append(b - a)
                if token == "*":
                    stack.append(a * b)   

               
                
        
        return stack.pop()
        


