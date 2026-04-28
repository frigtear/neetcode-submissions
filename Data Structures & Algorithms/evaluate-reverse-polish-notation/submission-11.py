class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # Input: tokens = ["1","2","+","3","*","4","-"]
        # -> 3 -> 3 * 4 -
        # -> 9
        operators = {'+', '-', '*', '/'}
        stack = list()
        for token in tokens:
            print(stack, token)
            if token in operators:
     
                l = stack.pop()
                r = stack.pop()
       
                if token == '+':
                    stack.append(l + r)
                elif token == '-':
                    stack.append(r - l)
                elif token == '/':
                    stack.append(int(r / l))
                else:
                    stack.append(l * r)
            
            else:
                stack.append(int(token))
        return stack.pop()

