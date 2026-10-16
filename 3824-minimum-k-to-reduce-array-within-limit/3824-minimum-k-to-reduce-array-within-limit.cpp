class Solution {
public:
    long long f(vector<int>& nums, int k) {
        long long cnt = 0;
        for (int x : nums) {
        cnt += (x + k - 1) / k;
        }
        return cnt;
    }
    int minimumK(vector<int>& nums) {
        int l = 1, h = 1e5;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (f(nums, mid) <= 1LL * mid * mid) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
