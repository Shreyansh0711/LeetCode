class Solution {
public:
    int jumps(int i, int j, int n, int m, vector<vector<int>>&obstacleGrid,
              vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (obstacleGrid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = jumps(i, j - 1, n, m, obstacleGrid, dp);
        int down = jumps(i - 1, j, n, m,obstacleGrid, dp);
        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return jumps(n-1, m-1, n, m,obstacleGrid ,dp);
    }
};