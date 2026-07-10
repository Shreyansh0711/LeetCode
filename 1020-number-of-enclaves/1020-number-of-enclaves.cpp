class Solution {
public:
    void dfs(vector<vector<int>>& arr, int i, int j,int n,int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || arr[i][j] != 1)
            return;

        arr[i][j] = 2;
        dfs(arr, i + 1, j,n,m);
        dfs(arr, i - 1, j,n,m);
        dfs(arr, i, j + 1,n,m);
        dfs(arr, i, j - 1,n,m);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0,n,m);

            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1,n,m);
        }

        // First and last row
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(grid, 0, j,n,m);

            if (grid[n - 1][j] == 1)
                dfs(grid, n - 1, j,n,m);
        }
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};