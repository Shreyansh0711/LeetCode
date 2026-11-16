class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<int>odr;
        odr.push_back(0);

        for(int i=0;i<odr.size();i++){
            int u=odr[i];
            for(int v:adj[u]){
                odr.push_back(v);
            }
        }
        vector<long long>dp(n,0);
        for(int i=n-1;i>=0;i--){
            int u=odr[i];

            if(adj[u].empty()){
                dp[u]=score[u];
                continue;
            }
            long long sm=0;
            long long mn=LLONG_MAX;

            for(int v:adj[u]){
                sm+=dp[v];
                mn=min(mn,dp[v]);
            }

            if(op[u]==0){
                dp[u]=score[u]+sm-min(0LL,mn);
            }else{
                dp[u]=score[u]+sm-mn;
            }
        }
        return dp[0];
    }
};