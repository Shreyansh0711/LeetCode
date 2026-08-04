class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        map<int,int>mp;
        for(int i:nums)mp[i]++;
        for(int i=nums[0];i<nums[nums.size()-1];i++){
            if(mp.count(i))continue;
            else ans.push_back(i);
        }
        return ans;
    }
};