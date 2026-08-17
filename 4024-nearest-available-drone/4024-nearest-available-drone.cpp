class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int dist=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            int curr=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if(curr<=drones[i][2]){
                if(curr<dist){
                    dist=curr;
                    ans=i;
                }
            }
        }
        
        return ans;
    }
};