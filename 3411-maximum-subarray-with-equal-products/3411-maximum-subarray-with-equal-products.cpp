class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = min(n, 2);

        for(int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;
            for(int j = i; j < n; j++) {
                if(gcd(l,nums[j])!=1)break;
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                prod *= nums[j];
                if(prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};