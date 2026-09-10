class Solution {
public:
    int find(int i,int m,int n,vector<string>& strs,vector<vector<vector<int>>>&dp){
        if(i==strs.size())return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int ans=find(i+1,m,n,strs,dp);
        int c0=0,c1=0;
        for(char c:strs[i]){
            if(c=='0')c0++;
            else c1++;
        }
        if(c0<=m&&c1<=n){
            ans=max(ans,1+find(i+1,m-c0,n-c1,strs,dp));
        }
        return dp[i][m][n]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return find(0,m,n,strs,dp);
    }
};