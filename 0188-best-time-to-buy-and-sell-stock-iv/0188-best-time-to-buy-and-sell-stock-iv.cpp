class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int x=1;x<=k;x++){
                    if(j==1){
                        dp[i][j][x]=max(dp[i+1][0][x]-prices[i],dp[i+1][1][x]);
                    }else{
                        dp[i][j][x]=max(dp[i+1][1][x-1]+prices[i],dp[i+1][0][x]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};