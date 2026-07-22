class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];

            adj[u].push_back({v, wt});
        }

        // {remaining stops, {cost, node}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][k+1]= 0;
        pq.push({0, {src, k+1}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second.first;
            int rem = it.second.second;

            if (node == dst)
                return d;

            if (rem == 0)
                continue;

            for (auto &next : adj[node]) {
                int adjNode = next.first;
                int wt = next.second;

                if (dist[adjNode][rem-1]> d + wt) {
                    dist[adjNode][rem-1]= d + wt;
                    pq.push({dist[adjNode][rem-1],{adjNode, rem-1}});
                }
            }
        }

        return -1;
    }
};