class Solution {
public:
    int match(int idx1,int idx2,string &text1,string &text2,vector<vector<int>>&dp){
        if(idx1<0||idx2<0) return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]){
            return 1+match(idx1-1,idx2-1,text1,text2,dp);
        }
        return dp[idx1][idx2]=max(match(idx1-1,idx2,text1,text2,dp),match(idx1,idx2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size()+1,-1)); 
        return match(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};