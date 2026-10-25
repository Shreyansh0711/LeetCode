class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j>=m||j<0||i>=n)return false;
        if (grid[i][j]==1) return true;
        grid[i][j]=1;
        return dfs(i,j+1,grid)&dfs(i,j-1,grid)&dfs(i+1,j,grid)&dfs(i-1,j,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    cnt+=dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};