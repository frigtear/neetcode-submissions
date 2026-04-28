class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # Input: target = 10,
        # position = [1,4],
        # speed = [3,2]
        # [(4, 2), (1,3)]
        # stack -> [(4,2)]
        # [(7, 1), (4, 2), (1, 2), (0, 1)]

        cars = sorted([(position[i], speed[i]) for i in range(len(position))],key=lambda car:car[0])[::-1]
        stack = list()
        fleets = 0
        for car in cars:
            time_to_target = (target - car[0]) / car[1]

            if stack and time_to_target <= stack[-1]:
                pass
            else:
                stack.append(time_to_target)
                fleets += 1

        return fleets

