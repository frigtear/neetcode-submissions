class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:

        
        # asteroids = [2,4,-4,-1]
        #              ^

        stack = list()
        for asteroid in asteroids:

            if stack and stack[-1] > 0 and asteroid < 0:

                while stack and stack[-1] > 0 and asteroid < 0:
                    
                    if abs(stack[-1]) == abs(asteroid):
                        stack.pop()
                        break

                    if max(abs(stack[-1]),abs(asteroid)) == abs(stack[-1]):
                        break
                    else:
                        stack.pop()

                else:
                    stack.append(asteroid)
            
            else:
                stack.append(asteroid)

            
                
                

            
            

        return stack
                

                
                
