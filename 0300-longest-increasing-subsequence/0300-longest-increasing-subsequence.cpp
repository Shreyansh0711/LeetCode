class Solution {
public:
    int find(int i,int pre,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][pre+1]!=-1)return dp[i][pre+1];
        int take=find(i+1,pre,nums,dp);
        
        if(pre==-1||nums[i]>nums[pre]){
            take=max(take,1+find(i+1,i,nums,dp));
        }
        return dp[i][pre+1]=take;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        if(is_sorted(nums.begin(),nums.end())&&nums[0]==nums[n-1])return 1;
        return find(0,-1,nums,dp);
    }
};