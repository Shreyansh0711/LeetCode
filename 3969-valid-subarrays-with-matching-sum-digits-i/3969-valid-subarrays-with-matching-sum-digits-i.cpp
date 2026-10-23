class Solution {
public:
    bool fun(long long sum, int x) {
        if (sum <= 0) return false;

        int last = sum % 10;

        while (sum >= 10) {
            sum /= 10;
        }

        return sum == x && last == x;
    }

    long long countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                long long sum = pre[r + 1] - pre[l];

                if (fun(sum, x)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};