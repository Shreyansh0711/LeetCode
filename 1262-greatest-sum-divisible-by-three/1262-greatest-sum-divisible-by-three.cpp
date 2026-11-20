class Solution {
public:
    int solve(vector<int>&nums,vector<vector<int>>&dp,int rem,int i){
        if(i>=nums.size()){
            if(rem==0)return 0;
            else return INT_MIN;
        }
        if(dp[i][rem]!=-1)return dp[i][rem];
        int pk=nums[i]+solve(nums,dp,(rem+nums[i])%3,i+1);
        int npk=solve(nums,dp,rem,i+1);
        return dp[i][rem]=max(pk,npk);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(3,INT_MIN));
        dp[n][0]=0;
        dp[n][1]=INT_MIN;
        dp[n][2]=INT_MIN;
        
        for(int i=n-1;i>=0;i--){
            for(int rem=0;rem<3;rem++){
                int pk=nums[i]+dp[i+1][(rem+nums[i])%3];
                int npk=dp[i+1][rem];
                dp[i][rem]=max(pk,npk);
            }
        }
        return dp[0][0];
    }
};