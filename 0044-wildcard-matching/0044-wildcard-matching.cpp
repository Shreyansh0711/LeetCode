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

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return find(n - 1, m - 1, s, p, dp);
    }
};