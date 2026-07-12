class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        vis[i][j] = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() &&
                grid[ni][nj] == '1' && vis[ni][nj] != 1) {
                dfs(ni, nj, vis, grid);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    islands++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return islands;
    }
};