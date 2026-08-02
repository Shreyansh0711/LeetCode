class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, LLONG_MIN));

        // Base case: sum of choosing 0 elements is 0
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, k); j++) {

                // Not pick
                dp[i][j] = dp[i - 1][j];

                // Pick
                if (j > 0 && dp[i - 1][j - 1] != LLONG_MIN) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i - 1][j - 1] + nums[i - 1]);
                }
            }
        }

        // Backtrack
        vector<int> ans;
        int i = n, j = k;

        while (i > 0 && j > 0) {

            // If value came from not picking
            if (dp[i][j] == dp[i - 1][j]) {
                i--;
            }
            else {
                ans.push_back(nums[i - 1]);
                i--;
                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};