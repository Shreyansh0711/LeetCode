class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=0;
        for(l=1;l<nums.size();l++){
            if(nums[l]!=nums[r]){ 
                r++;
                nums[r]=nums[l];
            }
        }
        return r+1;
    }
};