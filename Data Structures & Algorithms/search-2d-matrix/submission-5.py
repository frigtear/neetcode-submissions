class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        l, r = 0, len(matrix) - 1
        row_with_target_index = -1
        while l <= r:
            c = (l + r) // 2
            if matrix[c][0] <= target <= matrix[c][-1]:
                row_with_target_index = c
                break
            elif matrix[c][0] > target:
                r = c - 1
            else:
                l = c + 1

        target_row = matrix[row_with_target_index]
        l, r = 0, len(matrix[row_with_target_index]) - 1

        while l <= r:
            c = (l + r) // 2
            if target_row[c] == target:
                return True
            elif target_row[c] < target:
                l = c + 1
            else:
                r = c - 1
        return False





