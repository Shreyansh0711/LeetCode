class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x=nums[0];
        if(nums[0]==nums[nums.size()-1]&&nums[0]==0)return 0;
        for(int i=1;i<nums.size();i++){
            x^=nums[i];
        }
        
        if(x==0)return nums.size()-1;
        else return nums.size();
    }
};