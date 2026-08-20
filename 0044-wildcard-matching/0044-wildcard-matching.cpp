class Solution {
public:
    int find(int i, int j, string &s, string &p, vector<vector<int>>& dp) {
        if (i >= 0 && j < 0) return 0;

        if (i < 0 && j < 0) return 1;

        if (j >= 0 && i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return 0;
            }
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[j] == '*') {
            return dp[i][j] =
                find(i - 1, j, s, p, dp) |
                find(i, j - 1, s, p, dp);
        }
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = find(i - 1, j - 1, s, p, dp);
        }
        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        dp[0][0] = 1;
        for(int j=1;j<=m;j++){
            if(p[j-1]=='*')dp[0][j]=dp[0][j-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if (p[j-1] =='*') {
                    dp[i][j] =
                        dp[i - 1][j]|
                        dp[i][j - 1];
                }
                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};