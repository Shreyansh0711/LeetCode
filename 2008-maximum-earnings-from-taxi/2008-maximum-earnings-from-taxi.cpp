class Solution {
public:
    long long mem(int i,vector<long long>&dp,vector<vector<int>>&rides){
        if(i>=rides.size())return 0;
        if(dp[i]!=-1)return dp[i];
        long long take=rides[i][1]-rides[i][0]+rides[i][2];
        int l=i+1,r=rides.size()-1,nxt=rides.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(rides[mid][0]>=rides[i][1]){
                nxt=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        take+=mem(nxt,dp,rides);
        long long ntake=mem(i+1,dp,rides);
        return dp[i]=max(take,ntake);
    }
    long long maxTaxiEarnings(int n,vector<vector<int>>&rides){
        sort(rides.begin(),rides.end());
        vector<long long>dp(rides.size(),-1);
        return mem(0,dp,rides);
    }
};