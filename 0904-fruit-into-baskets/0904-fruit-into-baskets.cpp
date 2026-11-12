class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mxlen=0;
        int l=0;
        map<int,int>mp;
        for(int r=0;r<fruits.size();r++){
            mp[fruits[r]]++;
            while(mp.size()>2&&l<fruits.size()){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)mp.erase(fruits[l]);
                l++;
            }
            mxlen=max(mxlen,r-l+1);
        }
        return mxlen;
    }
};