class Solution {
public:
    int countDominantElements(vector<int>& a) {
        int n = a.size();
        int cnt = 0;

        if(n == 1) return 1;

        if(a[0] >= a[1]) cnt++;
        if(a[n-1] >= a[n-2]) cnt++;

        for(int i = 1; i < n-1; i++) {
            if(2LL * a[i] >= 1LL * a[i-1] + a[i+1])
                cnt++;
        }

        return cnt;
    }
};