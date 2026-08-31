class Solution {
public:
    vector<vector<int>>flipr(int i,vector<vector<int>>& grid){
        
        for(int k=0;k<grid[0].size();k++){
            if(grid[i][k]==0){
                grid[i][k]=1;
            }else{
                grid[i][k]=0;
            }
        }
        
        return grid;
    }
    vector<vector<int>>flipc(int j,vector<vector<int>>& grid){
        for(int k=0;k<grid.size();k++){
            if(grid[k][j]==0){
                grid[k][j]=1;
            }else{
                grid[k][j]=0;
            }
        }
        return grid;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                flipr(i,grid);
            }
        }
        for(int i=1;i<m;i++){
            int one=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1)one++;
            }
            int zr=n-one;
            if(zr>one){
                flipc(i,grid);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int val=0;
            for(int j=0;j<m;j++){
                val=(val<<1)+grid[i][j];
            }
            ans+=val;
        }
        return ans;
    }
};