class Solution {
public:
    int countConsistent(vector<int>& nums) {
        long long ans=0;
        vector<array<int,3>>seg;
        for(auto &x:nums){
            seg.push_back({x,x,1});
            int k=0;
            for(auto &s:seg){
                s[0]&=x;
                s[1]=min(s[1],x);
                if(k>1&&seg[k-1][0]==s[0]&&seg[k-1][1]==s[1])seg[k-1][2]+=s[2];
                else seg[k++]=s;
            }
            seg.resize(k);
            for(auto&s:seg){
                if(s[0]==s[1])ans+=s[2];
            }
        }
        return ans;
    }
};