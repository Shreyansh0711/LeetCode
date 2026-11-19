class Solution {
public:
    int MOD=1e9+7;

    int findPaths(int m, int n, int mx, int sr, int sc) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(mx+1,0)));
        vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};

        for(int k=1;k<=mx;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    for(vector<int>&d:dir){
                        int x=i+d[0];
                        int y=j+d[1];

                        if(x<0||x>=m||y<0||y>=n){
                            dp[i][j][k]=(dp[i][j][k]+1)%MOD;
                        }else{
                            dp[i][j][k]=(dp[i][j][k]+dp[x][y][k-1])%MOD;
                        }
                    }
                }
            }
        }

        return dp[sr][sc][mx];
    }
};