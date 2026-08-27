class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        
        int maxi=weight[0];
        int cnt=0;
        for(int i=1;i<n;i++){
            maxi=max(maxi,weight[i]);
            if(weight[i]<maxi){
                cnt++;

                if(i+1<n){
                    maxi=weight[i+1];
                }
            }
        }
        return cnt;
    }
};