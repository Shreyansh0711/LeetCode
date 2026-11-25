class Solution {
public:
    vector<vector<int>> ans;
    void solve(int node, vector<vector<int>>& adj, vector<int>& curr) {
        curr.push_back(node);
        if (node == adj.size() - 1) {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        for (auto it : adj[node]) {
            solve(it, adj, curr);
        }
        curr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> curr;
        solve(0, graph, curr);
        return ans;
    }
};