class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k}); 

        while (!pq.empty()) {

            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node])
                continue;

            for (auto it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if (dist[adjNode] > time + wt) {
                    dist[adjNode] = time + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};