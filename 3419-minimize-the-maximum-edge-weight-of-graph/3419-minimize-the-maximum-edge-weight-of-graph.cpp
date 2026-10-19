class Solution {
public:
    void dfs(int n,unordered_map<int,vector<pair<int,int>>>&mp,int mid,vector<bool>&vis){
        vis[n]=true;
        for(auto &p:mp[n]){
            int v=p.first;
            int u=p.second;

            if(u<=mid&&!vis[v]){
                vis[v]=true;
                dfs(v,mp,mid,vis);
            }
        }
    }
    bool check(int n,int mid,unordered_map<int,vector<pair<int,int>>>&mp){
        vector<bool>vis(n,false);
        dfs(0,mp,mid,vis);
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int,vector<pair<int,int>>>mp;
        int mxw=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            mp[v].push_back({u,w});
            mxw=max(mxw,w);
        }
        int res=INT_MAX;
        int l=0,r=mxw;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(n,mid,mp)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res==INT_MAX?-1:res;
    }
};