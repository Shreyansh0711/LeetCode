class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O')
            return;

        board[i][j] = 'T';

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();

        // First and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1);
        }

        // First and last row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[n - 1][j] == 'O')
                dfs(board, n - 1, j);
        }

        // Convert remaining O -> X and T -> O
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};