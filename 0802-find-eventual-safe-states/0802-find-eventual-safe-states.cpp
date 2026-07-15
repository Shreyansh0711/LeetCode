class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> rev(n);
        vector<int> outdegree(n);

        // Reverse graph and calculate outdegree
        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            for (int v : graph[i]) {
                rev[v].push_back(i);
            }
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int parent : rev[node]) {
                outdegree[parent]--;

                if (outdegree[parent] == 0)
                    q.push(parent);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};