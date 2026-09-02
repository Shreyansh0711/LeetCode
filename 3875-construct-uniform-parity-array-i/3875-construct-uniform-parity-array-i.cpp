class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cnte=1,cnto=1;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                cnte++;
            }else{
                cnto++;
            }
        }
        if(cnte==n||cnto==n)return true;
        for(int i=0;i<n-1;i++){
            if((nums1[i]-nums1[i+1])%2!=0)cnto++;
            if((nums1[i]-nums1[i+1])%2==0)cnte++;
        }
        if(cnte>=n||cnto>=n){
            return true;
        }
        return false;
    }
};