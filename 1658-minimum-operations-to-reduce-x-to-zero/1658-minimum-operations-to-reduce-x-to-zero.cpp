class Solution {
public:
    int find(int y,vector<int>&nums){
        int sm=0;
        int len=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            if(mp.find(sm-y)!=mp.end()){
                len=max(len,i-mp[sm-y]);
            }
            if(mp.find(sm)==mp.end()){
                mp[sm]=i;
            }
        }
        return len;
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sm=accumulate(nums.begin(),nums.end(),0);
        int y=sm-x;
        if(y==0)return n;
        int ans=find(y,nums);
        if(ans==0)return -1;
        return n-ans;
    }
};