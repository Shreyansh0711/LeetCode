class Solution {
public:
    int check(string &s,string &rev){
        vector<vector<int>> dp(s.size()+1, vector<int>(rev.size() + 1, 0));
        int n=s.size();
        int m=rev.size();
        for (int i = 0; i <=n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <=m; j++)
            dp[0][j] = 0;
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <=m; j++) {
                if (s[i-1] == rev[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        return check(s,rev);
    }
};