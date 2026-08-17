class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n=arrivalTime.size();
        int k=lights.size();
        int ans=0;
        sort(lights.begin(),lights.end());
        for(int i=0;i<n;i++){
            int r=arrivalTime[i]%period;
            if(r>=lights[k-1]){
                ans=max(ans,(period-r));
            }
        }
        return ans;
    }
};