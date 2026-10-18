class Solution {
public:
    int minDeletions(vector<int>& a) {
        int cnt=0;
        int n=a.size();
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                cnt++;
            }else{
                a[i-cnt]=a[i];
            }
        }
        return cnt;
    }
};