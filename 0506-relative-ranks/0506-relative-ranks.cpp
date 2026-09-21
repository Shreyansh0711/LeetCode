class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq;

        for(int x : score)
            pq.push(x);

        vector<string> ans(score.size());
        int rank = 1;

        while(!pq.empty()) {
            int nm = pq.top();
            pq.pop();

            for(int i = 0; i < score.size(); i++) {
                if(score[i] == nm) {
                    if(rank == 1)
                        ans[i] = "Gold Medal";
                    else if(rank == 2)
                        ans[i] = "Silver Medal";
                    else if(rank == 3)
                        ans[i] = "Bronze Medal";
                    else
                        ans[i] = to_string(rank);

                    break;
                }
            }

            rank++;
        }

        return ans;
    }
};