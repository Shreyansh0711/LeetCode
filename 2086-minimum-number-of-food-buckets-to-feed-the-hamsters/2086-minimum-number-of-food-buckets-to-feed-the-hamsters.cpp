class Solution {
public:
    int minimumBuckets(string hamsters) {
        vector<int>ham;
        for(int i=0;i<hamsters.size();i++){
            if(hamsters[i]=='H')ham.push_back(i);
        }
        int n=hamsters.size();
        if(ham.empty())return 0;
        vector<vector<int>>dp(n+1,vector<int>(2,1e9));
        int m=ham.size();
        for(int i=0;i<ham.size();i++){
            if(ham[i]-1>=0&&hamsters[ham[i]-1]=='.'){
                int flag=1;
                if(i&&ham[i]-ham[i-1]==2){
                    flag=0;
                }
                dp[i][0]=min((i?dp[i-1][0]:0)+1,(i?dp[i-1][1]:0)+flag);
            }
            if(ham[i]+1<n&&hamsters[ham[i]+1]=='.'){
                dp[i][1]=min((i?dp[i-1][0]:0)+1,(i?dp[i-1][1]:0)+1);
            }
        }
        return (min(dp[m-1][0],dp[m-1][1])>=1e9?-1:min(dp[m-1][0],dp[m-1][1]));
    }
};