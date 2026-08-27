class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();
        vector<vector<long long >>dp(n+1,vector<long long>(2,0));
        for(int i=0;i<n;i++){
            dp[i][0]=max((i?dp[i-1][0]:0)+energyDrinkA[i],(i?dp[i-1][1]:0));
            dp[i][1]=max((i?dp[i-1][1]:0)+energyDrinkB[i],(i?dp[i-1][0]:0));
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};