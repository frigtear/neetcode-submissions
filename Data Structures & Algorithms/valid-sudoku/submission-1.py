class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            row = set()
            for j in range(9):
                value = board[i][j]
                if value == "." or value not in row:
                    row.add(board[i][j])
                else:
                    print(row, "row")
                    return False


        for i in range(9):
            column = set()
            for j in range(9):
                value = board[j][i]
                if value == "." or value not in column:
                    column.add(board[j][i])
                else:
                    print(row, "col")
                    return False
        

        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                box = set()
                for row_offset in range(3):
                    for column_offset in range(3):
                        value = board[i + row_offset][j + column_offset]
                        if value == "." or value not in box:
                            box.add(value)
                        else:
                            print(row, "box")
                            return False

        return True

                