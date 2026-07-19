class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        while (!is_sorted(nums.begin(), nums.end())) {

            int idx = 0;
            int mn = INT_MAX;

            for (int i = 0; i < nums.size()-1; i++) {
                if (nums[i] + nums[i + 1] < mn) {
                    mn = nums[i] + nums[i + 1];
                    idx = i;
                }
            }

            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            ans++;
        }

        return ans;
    }
};