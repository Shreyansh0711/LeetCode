class Solution {
public:
    int jump(int idx, vector<int>& nums, vector<int>& dp) {

        if (idx == 0)
            return nums[0];

        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int rob = jump(idx - 2, nums, dp) + nums[idx];
        int notRob = jump(idx - 1, nums, dp);

        return dp[idx] = max(rob, notRob);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return jump(n - 1, nums, dp);
    }
};