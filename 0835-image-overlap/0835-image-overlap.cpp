class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        map<pair<int,int>, int> mp;
        vector<pair<int,int>> p;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1)
                    mp[{i,j}] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img2[i][j] == 1)
                    p.push_back({i,j});
            }
        }

        int ans = 0;
        for(int dr = -(n-1); dr <= n-1; dr++) {
            for(int dc = -(n-1); dc <= n-1; dc++) {
                int cnt = 0;
                for(auto it : p) {
                    int x = it.first + dr;
                    int y = it.second + dc;
                    if(mp[{x,y}] > 0)
                        cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};