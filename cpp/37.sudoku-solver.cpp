/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (36.85%)
 * Total Accepted:    130.4K
 * Total Submissions: 351.1K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * Empty cells are indicated by the character '.'.
 *
 *
 * A sudoku puzzle...
 *
 *
 * ...and its solution numbers marked in red.
 *
 * Note:
 *
 *
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 *
 *
 */
class Solution {
public:
    bool isSafe(const bool flag[3][9][9], int i, int j, char v) {
        char c = v - '1';
        return !(flag[0][i][c] || flag[1][j][c] || flag[2][i/3*3 + j/3][c]);
    }

    void setFlag(bool flag[3][9][9], int i, int j, char v, bool b) {
        char c = v - '1';
        flag[0][i][c] = flag[1][j][c] = flag[2][i/3*3 + j/3][c] = b;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool flag[3][9][9] = {false};
        vector<pair<char, char>> vp;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    char c = board[i][j] - '1';
                    flag[0][i][c] = flag[1][j][c] = flag[2][i/3*3 + j/3][c] = true;
                }
                else vp.push_back(make_pair(i, j));
            }
        }
        solve(board, flag, vp, 0);
    }

    bool solve(vector<vector<char>>& board, bool flag[3][9][9], vector<pair<char, char>>& vp, int curPos) {
        if (curPos == vp.size()) return true;
        int i = vp[curPos].first, j = vp[curPos].second;
        for (char k = '1'; k <= '9'; ++k) {
            if (isSafe(flag, i, j, k)) {
                board[i][j] = k;
                setFlag(flag, i, j, k, true);
                if (solve(board, flag, vp, curPos + 1)) return true;
                else setFlag(flag, i, j, k, false); // unset to recover the value of flag.
            }
        }
        return false;
    }
};
