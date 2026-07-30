class Solution {
public:
    bool find(int idx,int tar,vector<int>& nums,vector<vector<int>>&dp){
        if(tar==0)return true;
        if(idx==0)return (nums[idx]==tar);
        if(dp[idx][tar]!=-1){
            return dp[idx][tar];
        }
        bool notpick=find(idx-1,tar,nums,dp);
        bool pick=false;
        if(nums[idx]<=tar){
            pick=find(idx-1,tar-nums[idx],nums,dp);
        }
        return dp[idx][tar]=pick|notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sm=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size()+1,vector<int>(sm/2+1,-1));
        if(sm%2!=0){
            return false;
        }
        return find(nums.size()-1,sm/2,nums,dp);
    }
};