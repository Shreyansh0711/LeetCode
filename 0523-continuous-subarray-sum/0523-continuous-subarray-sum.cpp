class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = -1;
        int sm = 0;
        for (int i = 0; i < n; i++) {
           sm+=nums[i];
           if(mp.find(sm%k)!=mp.end()){
            if(i-mp[sm%k]>=2)return true;
           }
           else mp[sm%k]=i;
        }
        return false;
    }
};