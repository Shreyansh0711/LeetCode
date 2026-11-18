class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        if(n==1)return {1};

        vector<vector<int>>adj(n+1);

        for(auto i:paths){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }

        vector<int>clr(n,0);

        for(int i=0;i<n;i++){
            if(clr[i]==0){
                queue<int>q;
                q.push(i);
                clr[i]=1;

                while(!q.empty()){
                    int curr=q.front();
                    q.pop();

                    for(auto c:adj[curr]){
                        if(clr[c]==0){
                            vector<int>vis(5,0);

                            for(auto x:adj[c]){
                                vis[clr[x]]=1;
                            }

                            for(int j=1;j<=4;j++){
                                if(!vis[j]){
                                    clr[c]=j;
                                    break;
                                }
                            }

                            q.push(c);
                        }
                    }
                }
            }
        }

        return clr;
    }
};