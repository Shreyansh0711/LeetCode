class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        map<pair<int,int>,int>mp;
        int n=grid.size();
        int m=grid[0].size();
        int i=0,j=0;
        vector<int>ans;
        while(i>=0&&i<n&&j>=0&&j<m){
            if(mp[{i,j}]>0){
                break;
            }
            ans={i,j};
            mp[{i,j}]++;
            if (grid[i][j] == 'R') j++;
            else if (grid[i][j] == 'L') j--;
            else if (grid[i][j] == 'U') i--;
            else if (grid[i][j] == 'D') i++;
        }
        return ans;
    }
};