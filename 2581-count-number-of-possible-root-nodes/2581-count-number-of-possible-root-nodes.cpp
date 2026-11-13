class Solution {
public:
    void corr(int node,vector<vector<int>>&adj,set<pair<int,int>>&pr,int &cr,int par){
        for(auto &v:adj[node]){
            if(v!=par){
                if(pr.count({node,v}))cr++;
                corr(v,adj,pr,cr,node);
            }
        }
    }

    void reroot(int node,vector<vector<int>>&adj,set<pair<int,int>>&pr,int &res,int &cr,int k,int par=-1){
        if(cr>=k)res++;

        for(auto &v:adj[node]){
            if(v!=par){
                if(pr.count({node,v}))cr--;
                if(pr.count({v,node}))cr++;

                reroot(v,adj,pr,res,cr,k,node);

                if(pr.count({v,node}))cr--;
                if(pr.count({node,v}))cr++;
            }
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        set<pair<int,int>>pr;

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(auto &g:guesses){
            pr.insert({g[0],g[1]});
        }

        int res=0,cnt=0;
        corr(0,adj,pr,cnt,-1);
        reroot(0,adj,pr,res,cnt,k);

        return res;
    }
};