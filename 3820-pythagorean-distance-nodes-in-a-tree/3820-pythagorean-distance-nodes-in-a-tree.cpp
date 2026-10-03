class Solution {
public:
    vector<int> solve(int i,vector<vector<int>>&adj,int n){
        vector<int>d(n,-1);
        d[i]=0;
        deque<int>q;
        q.push_back(i);
        while(!q.empty()){
            int curr=q.front();
            q.pop_front();
            for(auto &i:adj[curr]){
                if(d[i]==-1){
                    q.push_back(i);
                    d[i]=d[curr]+1;
                }
            }
        }
        return d;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        vector<int>dx=solve(x,adj,n),dy=solve(y,adj,n),dz=solve(z,adj,n);
        for(int i=0;i<n;i++){
            vector<int>a;
            a.push_back(dx[i]);
            a.push_back(dy[i]);
            a.push_back(dz[i]);
            sort(a.begin(),a.end());
            if(1LL*a[0]*a[0] + 1LL*a[1]*a[1] == 1LL*a[2]*a[2])cnt++;
        }
        return cnt;
    }
};