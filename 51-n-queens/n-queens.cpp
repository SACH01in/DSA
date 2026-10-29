class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false);
        vector<bool> diag2(2 * n, false);
        
        backtrack(0, n, board, cols, diag1, diag2, solutions);
        return solutions;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n;
            int d2 = row + col;
            
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }
            
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            
            backtrack(row + 1, n, board, cols, diag1, diag2, solutions);
            
            board[row][col] = '.';
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
};