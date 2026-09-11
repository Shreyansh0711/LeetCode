class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>mp(10,0);
        for(int x:digits)mp[x]++;
        
        
        int ans=0;
        for(int i=0;i<=8;i+=2){
            if(mp[i]==0)continue;
            mp[i]--;
            for(int j=1;j<=9;j++){
                if(mp[j]==0)continue;
                mp[j]--;
                for(int k=0;k<=9;k++){
                    if(mp[k]>0)ans++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return ans;
    }
};