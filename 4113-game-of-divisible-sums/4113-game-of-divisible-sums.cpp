class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            long long sum=nums[i];
            long long tk1=(sum%3==0)?sum-dp[i+1]:sum+dp[i+1];
            long long tk2=LLONG_MIN;
            if(i+1<n){
                sum+=nums[i+1];
                tk2=(sum%3==0)?sum-dp[i+2]:sum+dp[i+2];
            }
            dp[i]=max(tk1,tk2);
        }
        return dp[0];
    }
};