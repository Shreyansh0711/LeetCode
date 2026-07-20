class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        vector<vector<int>> id(n, vector<int>(m, 0));

        int node = 1;

        // Number every zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    id[i][j] = node++;
            }
        }

        int zeros = node - 1;

        // adj[u] = {v, weight}
        vector<vector<pair<int, int>>> adj(node);

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != 0)
                    continue;

                int u = id[i][j];

                for (int k = 0; k < 8; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                        grid[ni][nj] == 0) {

                        int v = id[ni][nj];
                        adj[u].push_back({v, 1}); // weight = 1
                    }
                }
            }
        }

        vector<int> dist(node, INT_MAX);

        set<pair<int, int>> st;
        int start = 1;
        st.insert({0, start});
        dist[start] = 0;

        while (!st.empty()) {
            auto [d, u] = *st.begin();
            st.erase(st.begin());

            for (auto [v, wt] : adj[u]) {
                if (dist[v] > d + wt) {
                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }

                    dist[v] = d + wt;
                    st.insert({dist[v], v});
                }
            }
        }
        if (dist[node - 1] == INT_MAX)
            return -1;

        return dist[node - 1] + 1;
    }
};