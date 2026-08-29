class Solution {
public:
    int find(int i,vector<int>& pnt,vector<int>&dp){
        if(i==0)return pnt[i];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int take = pnt[i] + find(i - 2, pnt, dp);
        int ntake = find(i - 1, pnt, dp);

        return dp[i] = max(take, ntake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>pnt(mx+1,0);
        for(int i:nums)pnt[i]+=i;
        vector<int>dp(mx+1,-1);
        return find(mx, pnt, dp);
    }
};