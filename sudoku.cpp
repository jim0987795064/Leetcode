class Solution {

private:
    vector<vector<char>> copy;
    vector<vector<vector<char>>> candidate;

    bool checkResult = false, solved = false;

    int startRow = 0, startCol = 0, row = 0, col = 0, currentRow = 0,
        currentCol = 0;

public:
    void solveSudoku(vector<vector<char>>& board) {

        copy = board;

        solver(board, currentRow, currentCol);

        return;
    }

    void solver(vector<vector<char>>& board, int i, int j) {

        if (copy[i][j] == '.')
            for (char c = '1'; c < '10'; c++) {

                board[i][j] = c;

                checkResult = check(board, i, j);

                if (checkResult) {

                    if (i == 8 && j == 8) {

                        solved = true;
                        return;
                    }

                    if (j == 8) {
                        i++;
                        j = 0;
                        solver(board, i, j);

                        if (solved)
                            return;
                        checkResult = false;
                        i--;
                        j = 8;

                    } else {
                        j++;
                        solver(board, i, j);

                        if (solved)
                            return;

                        checkResult = false;
                        j--;
                    }
                }

                if (c == '9') {
                    board[i][j] = '.';
                    return;
                }
            }

        else if (i == 8 && j == 8) {

            solved = true;
            return;
        }

        else if (j == 8) {
            i++;
            j = 0;
            solver(board, i, j);
        } else {
            j++;
            solver(board, i, j);
        }
    }

    bool check(vector<vector<char>>& board, int current_row, int current_col) {

        startRow = (current_row / 3) * 3;
        startCol = (current_col / 3) * 3;

        for (int i = 0; i < 9; i++)
            if (board[i][current_col] == board[current_row][current_col] &&
                i != current_row)
                return false;

        for (int j = 0; j < 9; j++)
            if (board[current_row][j] == board[current_row][current_col] &&
                j != current_col)
                return false;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {

                for (int k = 0; k < 9; k++) {

                    row = startRow + k / 3;
                    col = startCol + k % 3;

                    if (row != current_row && col != current_col &&
                        board[row][col] == board[current_row][current_col])
                        return false;
                }
            }

        return true;
    }
};