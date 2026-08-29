class Solution {
public:
    int find(int i,int j,string &s,vector<vector<int>>&dp){
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int ways=0;
        ways=find(i+1,j,s,dp);
        if(i+1<=j){
            int x=(s[i]-'0')*10+(s[i+1]-'0');
            if(x>=10&&x<=26){
                ways+=find(i+2,j,s,dp);
            }
        }
        return dp[i][j]=ways;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return find(0,n-1,s,dp);
    }
};