class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=nums[0];
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==1)return nums[0];
        if(nums[0]!=nums[1]&&n>1)return nums[0];
        if(nums[n-2]!=nums[n-1]&&n>1)return nums[n-1];
        for(int i=1;i<n-1;i++){
           if(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1])return nums[i];
        }
        return 0;
    }
};