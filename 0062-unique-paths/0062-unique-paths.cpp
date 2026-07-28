class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1||j==m-1){
                    dp[i][j]=1;
                }else{
                    int right=dp[i][j+1];
                    int down=dp[i+1][j];
                    dp[i][j]=right+down;
                }
            }
        }
        return dp[0][0];
    }
};