class Solution {
public:
    int n,m;
    long long divk(int i,int j,vector<vector<int>>& grid){
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return 0; 
        long long val = grid[i][j]; 
        grid[i][j] = 0; 
        val += divk(i, j + 1, grid);
        val += divk(i, j - 1, grid);
        val += divk(i + 1, j, grid); 
        val += divk(i - 1, j, grid);
        return val;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    long long sm =divk(i,j,grid);
                    if(sm%k==0)cnt++;
                }
            }
        }
        return cnt;
    }
};