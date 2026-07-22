class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int diff=0;
        int n=nums.size();
        if(n==1)return 0;
        for(int i=0;i<n-1;i++){
            diff=max(diff,nums[i+1]-nums[i]);
        }
        return diff;
    }
};