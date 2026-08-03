class Solution {
public:
    int find(int idx, int tar, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (tar % coins[idx] == 0)
                return tar / coins[idx];
            else
                return INT_MAX;
        }
        if (dp[idx][tar] != -1)
    return dp[idx][tar];
        int ntake = find(idx - 1, tar, coins, dp);
        int take = INT_MAX;
        if (coins[idx] <= tar) {
            int res = find(idx, tar - coins[idx], coins, dp);
            if (res != INT_MAX)
                take = 1 + res;
        }
        return dp[idx][tar] = min(take, ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = find(n - 1, amount, coins, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};