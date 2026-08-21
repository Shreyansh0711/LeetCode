class Solution {
public:
    int find(int idx, int tar, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (tar % coins[idx] == 0)
                return tar / coins[idx];
            else
                return 1e9;
        }
        if (dp[idx][tar] != -1)
        return dp[idx][tar];
        int ntake = find(idx - 1, tar, coins, dp);
        int take = 1e9;
        if (coins[idx] <= tar) {
            take = 1+find(idx, tar - coins[idx], coins, dp);
        }
        return dp[idx][tar] = min(take, ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = find(n - 1, amount, coins, dp);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};