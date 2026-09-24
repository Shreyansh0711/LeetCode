class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sm=0;
            int nm=nums[i];
            while(nm>0){
                sm+=nm%10;
                nm/=10;
            }
            if(sm==i)return i;
        }
        return -1;
    }
};