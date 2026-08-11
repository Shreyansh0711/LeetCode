class Solution {
public:
    bool find(int n, vector<int>& dp) {
        if (n == 0) return false;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++) {
            int sq = i * i;
            if (!find(n - sq, dp)) {
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);

        return find(n, dp);
    }
};