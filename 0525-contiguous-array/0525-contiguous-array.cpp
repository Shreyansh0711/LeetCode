class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int minlen=INT_MAX;
        int n=nums.size();
        map<int,int>mp;
        mp[0]=-1;
        int one=0,zero=0;
        int ans=0;
        for(int r=0;r<n;r++){
            if(nums[r]==1)one++;
            else zero++;
            int dif=zero-one;
            if(mp.count(dif)){
                ans=max(ans,r-mp[dif]);
            }
            else mp[dif]=r;
        }
        return ans;
    }
};