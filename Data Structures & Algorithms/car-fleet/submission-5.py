class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        

        cars = sorted([(pos, spd) for pos, spd in zip(position, speed)], reverse = True)

        stack = list()
        for car in cars:
            pos, spd = car[0], car[1]
            time = (target - pos) / spd
            
            if not stack or stack[-1] < time:
                stack.append(time)


        return len(stack)

            
