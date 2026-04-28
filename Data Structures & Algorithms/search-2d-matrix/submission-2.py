class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:


        l, r = 0, len(matrix) - 1
        target_row = matrix[0]
        while l <= r:

            mid = (l + r) // 2
            row = matrix[mid]
            if row[0] <= target <= row[-1]:
                target_row = row
                break
            elif target < row[0]:
                r = mid - 1
            else:
                l = mid + 1

        l, r = 0, len(target_row) - 1

        while l <= r:
            mid = (l + r) // 2
            
            if target == target_row[mid]:
                return True
            elif target > target_row[mid]:
                l = mid + 1
            else:
                r = mid - 1

        return False


        
        