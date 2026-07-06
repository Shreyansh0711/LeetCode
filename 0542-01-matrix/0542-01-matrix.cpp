class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>d(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    d[i][j]=0;
                }
            }
        }
        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int nx=r+row[k];
                int ny=c+col[k];

                if(nx>=0&&ny>=0&&nx<n&&ny<m&&d[nx][ny]==-1){
                    d[nx][ny]=d[r][c]+1;
                    q.push({nx,ny});
                }
            }
        }
        return d;
    }
};