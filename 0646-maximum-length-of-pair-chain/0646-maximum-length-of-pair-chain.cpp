class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int cnt = 1;
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int i = 0, j = 0;
        int n = pairs.size();
        while (i < n && j + 1 < n) {
            j = i + 1;
            while (pairs[i][1] >= pairs[j][0] && j < n - 1) {
                j++;
            }
            if (pairs[i][1] < pairs[j][0])
                cnt++;
            i = j;
        }
        return cnt;
    }
};