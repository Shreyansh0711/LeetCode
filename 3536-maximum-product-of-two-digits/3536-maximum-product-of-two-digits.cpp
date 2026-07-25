class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n>0){
            ans.push_back(n%10);
            n/=10;
        }
        sort(ans.begin(),ans.end());
        int k=ans.size();
        int pro=ans[k-1]*ans[k-2];
        return pro;
    }
};