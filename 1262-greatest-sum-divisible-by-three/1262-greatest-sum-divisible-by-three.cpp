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
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return solve(nums,dp,0,0);
    }
};