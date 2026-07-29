class Solution {
public:
    int choc(int i, int j, int k, int n, int m, vector<vector<int>>& grid,
             vector<vector<vector<int>>>& dp) {
        if (j < 0 || k < 0 || j >= m || k >= m)
            return INT_MIN;
        if (i == n - 1) {
            if (j == k)
                return grid[i][j];
            else
                return grid[i][j] + grid[i][k];
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int maxi = INT_MIN;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int val = 0;
                if (j == k)
                    val = grid[i][j];
                else
                    val = grid[i][j] + grid[i][k];
                val += choc(i + 1, j + di, k + dj, n, m, grid, dp);
                maxi = max(maxi, val);
            }
        }
        return dp[i][j][k] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        return choc(0, 0, m - 1, n, m, grid, dp);
    }
};