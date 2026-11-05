class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> d;

        vector<vector<int>> p = {p1,p2,p3,p4};

        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                int x=p[i][0]-p[j][0];
                int y=p[i][1]-p[j][1];

                d.push_back(x*x+y*y);
            }
        }

        sort(d.begin(),d.end());

        return d[0]>0 &&
               d[0]==d[1] &&
               d[1]==d[2] &&
               d[2]==d[3] &&
               d[4]==d[5] &&
               d[4]==2*d[0];
    }
};