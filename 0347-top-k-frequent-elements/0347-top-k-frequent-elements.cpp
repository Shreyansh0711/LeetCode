class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        vector<int> ans;
        map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        ans.reserve(k);
        priority_queue<pair<int, int>> pq;

        // {frequency, element}
        for (auto& it : mp) {
            pq.push({it.second, it.first});
        }

        while (k-- && !pq.empty()) {
            auto [freq, element] = pq.top();
            pq.pop();
            ans.push_back(element);
        }

        return ans;
    }
};