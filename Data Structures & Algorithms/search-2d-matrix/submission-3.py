class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        l, r = 0, len(matrix) - 1
        row = []
        while l <= r:
            c = (l + r) // 2
            if matrix[c][0] <= target <= matrix[c][-1]:
                row = matrix[c]
                break
            elif target < matrix[c][0]:
                r = c - 1
            else:
                l = c + 1
        
        l,r = 0, len(row) - 1

        while l <= r:
            c = (l + r) // 2
            if row[c] == target:
                return True
            elif row[c] < target:
                l = c + 1
            else:
                r = c - 1
        return False

            
