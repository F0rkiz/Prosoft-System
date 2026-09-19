class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // Это была 1 задачка с этого кода я не кайфую
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backtrack(ans, board, 0, n);
        return ans;
    }

    void backtrack(vector<vector<string>>& ans, vector<string>& board, int i, int n) {
        if (i == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (check(board, i, j, n)) {
                board[i][j] = 'Q';
                backtrack(ans, board, i + 1, n);
                board[i][j] = '.';
            }

        }
    }

    bool check(vector<string>& board, int row, int col, int n) {
        for (int j = 0; j < n; j++) {
            if (board[j][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};