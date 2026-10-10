class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int x=(arr[i]%k+k)%k;
            mp[x]++;
        }
        if(mp[0]%2!=0)return false;
        for(int i=1;i<=k/2;i++){
            if(i==k-i){
                if(mp[i]%2!=0)return false;
            }
            else if(mp[i]!=mp[k-i])return false;
        }
        return true;
    }
};