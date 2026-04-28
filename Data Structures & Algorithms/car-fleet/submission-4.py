class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # (target - position) // speed 
        stack = list()
        cars = sorted(zip(position, speed), reverse = True)

        for car in cars:
            time = (target - car[0]) / car[1]

            if not stack or time > stack[-1]:
                stack.append(time)

        return len(stack)






