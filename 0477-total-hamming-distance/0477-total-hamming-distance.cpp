class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=nums[i]^nums[j];
                ans+=__builtin_popcount(x);
            }
        }
        return ans;
    }
};