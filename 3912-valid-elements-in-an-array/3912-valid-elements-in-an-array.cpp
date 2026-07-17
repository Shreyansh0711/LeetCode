class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> lm(n), rm(n);
        lm[0] = nums[0];
        for(int i = 1; i < n; i++) {
            lm[i] = max(lm[i-1], nums[i]);
        }
        rm[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            rm[i] = max(rm[i+1], nums[i]);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n-1 ||
               nums[i] > lm[i-1] ||
               nums[i] > rm[i+1]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};