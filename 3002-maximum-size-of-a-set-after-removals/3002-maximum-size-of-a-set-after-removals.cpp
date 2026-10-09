class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() / 2;
        set<int> s1, s2, ans;

        s1.insert(nums1.begin(), nums1.end());
        s2.insert(nums2.begin(), nums2.end());
        int cnt1=0,cnt2=0;
        for(auto it:s2){
            if(cnt2==n)break;
            if(s1.find(it)!=s1.end())continue;
            ans.insert(it);
            cnt2++;
        }
        for(auto it:s1){
            if(cnt1==n)break;
            if(s2.find(it)!=s2.end())continue;
            ans.insert(it);
            cnt1++;
        }
        if(s1.size()>s2.size()){
            for(auto it:s2){
                if(cnt2==n)break;
                if(ans.find(it)!=ans.end())continue;
                ans.insert(it);
                cnt2++;
            } 
            for(auto it:s1){
                if(cnt1==n)break;
                if(ans.find(it)!=ans.end())continue;
                ans.insert(it);
                cnt1++;
            }
        }else{
            for(auto it:s1){
                if(cnt1==n)break;
                if(ans.find(it)!=ans.end())continue;
                ans.insert(it);
                cnt1++;
            }
            for(auto it:s2){
                if(cnt2==n)break;
                if(ans.find(it)!=ans.end())continue;
                ans.insert(it);
                cnt2++;
            }
        }
        return ans.size();
    }
};

