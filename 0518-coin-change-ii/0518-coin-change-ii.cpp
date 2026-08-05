class Solution {
public:
    int find(int idx,int tar,vector<int>&coins,vector<vector<int>>&dp){
        if (idx == 0) {
            if (tar == coins[idx])
                return 1;
            else if(tar%coins[idx]==0)
                return 1;
            else return 0;
        }
        if(dp[idx][tar]!=-1){
            return dp[idx][tar];
        }
        int ntake = find(idx - 1, tar, coins, dp);
        int take = 0;
        if (coins[idx] <= tar) {
            take = find(idx, tar - coins[idx], coins, dp);
        }
        return dp[idx][tar]=(take+ntake);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return find(coins.size()-1,amount,coins,dp);
    }
};