class Solution {
public:

    int lca(vector<int>& h) {
        stack<int> st;
        int mx = 0;
        int n = h.size();

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || h[st.top()] >= h[i])) {

                int hi = h[st.top()];
                st.pop();

                int w;

                if (st.empty()) {
                    w = i;
                } else {
                    w = i - st.top() - 1;
                }

                mx = max(mx, hi * w);
            }

            st.push(i);
        }

        return mx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h(m, 0);
        int mxa = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    h[j]++;
                } else {
                    h[j] = 0;
                }
            }
            int area = lca(h);
            mxa = max(mxa, area);
        }
        return mxa;
    }
};