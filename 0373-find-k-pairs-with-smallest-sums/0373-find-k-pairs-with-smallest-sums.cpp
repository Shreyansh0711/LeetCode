class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        for(int i=0;i<min(n1,k);i++)
        {
            int sum = nums1[i] + nums2[0];
            pq.push({sum,{i,0}});
        }

        int cnt = 0;
        vector<vector<int>>ans;
        while(!pq.empty()   &&  cnt<k)
        {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i],nums2[j]});
            cnt++;

            if(j+1<n2) pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }

        return ans;
    }
};