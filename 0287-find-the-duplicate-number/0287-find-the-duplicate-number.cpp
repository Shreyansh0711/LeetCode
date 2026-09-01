class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int k = upper_bound(nums.begin(), nums.end(), nums[i]) -
                    lower_bound(nums.begin(), nums.end(), nums[i]);
            if (k >= 2) {
                return nums[i];
            }
        }
        return 0;
    }
};