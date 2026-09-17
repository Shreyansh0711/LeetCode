class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sm=0,l=0;
        int n=arr.size();
        vector<int>a(n,INT_MAX);
        int ans=INT_MAX,prev=INT_MAX;
        for(int r=0;r<n;r++){
            sm+=arr[r];
            while(sm>target){
                sm-=arr[l];
                l++;
            }
            if(sm==target){
                int len=r-l+1;
                if(l>0&&a[l-1]!=INT_MAX){
                    ans=min(ans,a[l-1]+len);
                }
                prev=min(prev,len);
            }
            a[r]=prev;
        }
        return ans==INT_MAX?-1:ans;
    }
};