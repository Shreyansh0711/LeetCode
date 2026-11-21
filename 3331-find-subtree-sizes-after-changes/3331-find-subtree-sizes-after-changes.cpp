class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>res;
    vector<int>last;

    void solve(int curr,string &s,vector<int>&parent){
        int c=s[curr]-'a';
        int nr=last[c];

        last[c]=curr;

        for(int ch:adj[curr]){
            solve(ch,s,parent);
        }

        last[c]=nr;

        if(curr!=0){
            int np=parent[curr];

            if(nr!=-1)np=nr;

            parent[curr]=np;
            res[np]+=res[curr];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();

        for(int i=1;i<n;i++){
            int u=parent[i];
            int v=i;
            adj[u].push_back(v);
        }

        res.assign(n,1);
        last.assign(26,-1);

        solve(0,s,parent);

        return res;
    }
};