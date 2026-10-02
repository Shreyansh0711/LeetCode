class Solution {
public:
    long long solve(int i, vector<vector<int>>&adj,vector<int>& t){
        if(adj[i].size()==0)return t[i];
        long long mini=LLONG_MAX;
        long long maxi=0;
        for(auto it:adj[i]){
            long long a=solve(it,adj,t);
            mini=min(mini,a);
            maxi=max(maxi,a);
        }
        long long own=(maxi-mini)+t[i];
        long long end=own+maxi;
        return end;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        return solve(0,adj,baseTime);
    }
};