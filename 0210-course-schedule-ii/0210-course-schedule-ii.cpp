class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& ans) {

        vis[node] = 1; // visiting

        for (auto child : adj[node]) {

            if (vis[child] == 1)
                return false; // cycle

            if (vis[child] == 0) {
                if (!dfs(child, adj, vis, ans))
                    return false;
            }
        }

        vis[node] = 2; // completely visited
        ans.push_back(node);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &it : prerequisites) {
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, adj, vis, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};