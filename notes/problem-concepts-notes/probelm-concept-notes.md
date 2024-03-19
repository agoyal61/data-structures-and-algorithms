
- transpose of a matrix : flip rows and columns of matrix

- For each square on a given diagonal, the difference between the row and column indices (row - col) will be constant.

- For each square on a given anti-diagonal, the sum of the row and column indexes (row + col) will be constant. If you were to start at the highest square in an anti-diagonal and move downwards, the row index increments by 1 (row + 1), and the column index decrements by 1 (col - 1). These cancel each other out.

-  total lowerDiagonal (n-1+row-col) = total upper diagonal (row+col) = 2*n-1 , where n is dimension of grid or board
- Box index sudoku: box_index = (row / 3) * 3 + column / 3
backtrack(row = 0, col = 0) , If we're on the last cell row == 8, col == 8: That means that we've solved the sudoku.

