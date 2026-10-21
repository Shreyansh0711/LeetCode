class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            int nm=spells[i];
            int l=0,h=m-1;
            int cnt=0;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(1LL*potions[mid]*nm>=success){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }
            ans.push_back(m-l);
        }
        return ans;
    }
};