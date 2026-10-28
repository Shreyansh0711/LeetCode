class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(m));
        dp[0][0].insert(grid[0][0]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 < n) {
                    for (int x : dp[i][j])
                        dp[i + 1][j].insert(x ^ grid[i + 1][j]);
                }

                if (j + 1 < m) {
                    for (int x : dp[i][j])
                        dp[i][j + 1].insert(x ^ grid[i][j + 1]);
                }
            }
        }

        return *min_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
    }
};