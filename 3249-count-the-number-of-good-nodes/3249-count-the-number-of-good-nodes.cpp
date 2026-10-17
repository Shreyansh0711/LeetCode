class Solution {
public:
    int ans=0;
    int dfs(vector<vector<int>>&adj,int k,int root){
        int size=1;
        int prev=-1;
        bool good=true;
        for(int x:adj[k]){
            if(x==root)continue;//skiping parent
            int cldsize=dfs(adj,x,k);
            if(prev!=-1&&prev!=cldsize){
                good=false;
            }
            prev=cldsize;
            size+=cldsize;
        }
        if(good)ans++;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(int j=0;j<edges.size();j++){
            adj[edges[j][0]].push_back(edges[j][1]);
            adj[edges[j][1]].push_back(edges[j][0]);
        }
        dfs(adj,0,-1);
        return ans;
    }
    
};