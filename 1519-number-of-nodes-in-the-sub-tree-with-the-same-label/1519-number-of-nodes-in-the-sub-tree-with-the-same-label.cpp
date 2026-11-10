class Solution {
public:
    vector<vector<int>> ad;
    vector<int> res;
    string labels;

    vector<int> dfs(int curr, int pr) {
        vector<int> cnt(26, 0);

        cnt[labels[curr] - 'a']++;

        for (int v : ad[curr]) {
            if (v == pr) continue;

            vector<int> child = dfs(v, curr);

            for (int i = 0; i < 26; i++) {
                cnt[i] += child[i];
            }
        }

        res[curr] = cnt[labels[curr] - 'a'];

        return cnt;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        ad.resize(n);
        res.resize(n, 0);
        labels = s;

        for (auto &it : edges) {
            ad[it[0]].push_back(it[1]);
            ad[it[1]].push_back(it[0]);
        }

        dfs(0, -1);

        return res;
    }
};