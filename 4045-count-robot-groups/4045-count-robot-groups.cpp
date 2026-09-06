class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=speed.size();
        pair<int,int>p;
        int ans=1;
        p={speed[n-1],position[n-1]};
        for(int i=n-2;i>=0;i--){
            if(speed[i]>p.first||p.second-position[i]<=distance){
                p={p.first,position[i]};
            }else{
                ans++;
                p={speed[i],position[i]};
            }
        }
        return ans;
    }
};