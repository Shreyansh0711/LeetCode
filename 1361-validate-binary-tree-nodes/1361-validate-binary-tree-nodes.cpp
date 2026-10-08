class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(lc[i]!=-1){
                if(mp[lc[i]]++)return false;
            }
            if(rc[i]!=-1){
                if(mp[rc[i]]++)return false;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(mp[i]==0){
                if(root!=-1)return false;
                root=i;
            }
        }
        if(root==-1)return false;
        map<int,bool>vis;
        queue<int>q;

        q.push(root);
        vis[root]=true;

        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            if(lc[node]!=-1){
                if(vis[lc[node]])return false;

                vis[lc[node]]=true;
                q.push(lc[node]);
            }

            if(rc[node]!=-1){
                if(vis[rc[node]])return false;

                vis[rc[node]]=true;
                q.push(rc[node]);
            }
        }
        return cnt==n;
    }
};