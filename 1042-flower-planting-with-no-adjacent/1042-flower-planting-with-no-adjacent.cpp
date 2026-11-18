class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& clr) {
        vector<int>vis(5,0);

        for(auto c:adj[node]){
            vis[clr[c]]=1;
        }

        for(int j=1;j<=4;j++){
            if(!vis[j]){
                clr[node]=j;
                break;
            }
        }

        for(auto c:adj[node]){
            if(clr[c]==0){
                dfs(c,adj,clr);
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n);

        for(auto i:paths){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }

        vector<int>clr(n,0);

        for(int i=0;i<n;i++){
            if(clr[i]==0)dfs(i,adj,clr);
        }

        return clr;
    }
};