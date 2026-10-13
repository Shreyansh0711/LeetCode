class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int> pre(n), suff(n);

        pre[0] = v[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * v[i];
        }

        suff[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * v[i];
        }

        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0)
                ans[i] *= pre[i - 1];

            if (i + 1 < n)
                ans[i] *= suff[i + 1];
        }

        return ans;
    }
};