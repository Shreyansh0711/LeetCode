class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {

        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int j = 0;
        int lastCnt = 0;

        for (int i = 0; i < buses.size(); i++) {
            int cnt = 0;
            while (j < passengers.size() &&
                   passengers[j] <= buses[i] &&
                   cnt < capacity) {

                j++;
                cnt++;
            }
            if (i == buses.size() - 1)
                lastCnt = cnt;
        }
        int ans;
        if (lastCnt < capacity) {
            ans = buses.back();
        }
        else {
            ans = passengers[j - 1] - 1;
        }
        set<int> st(passengers.begin(), passengers.end());

        while (st.count(ans)) {
            ans--;
        }

        return ans;
    }
};