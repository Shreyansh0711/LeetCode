class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        map<long long, int> mp;
        
        for(int i = 0; ; i++){
            long long xcurr = pow(x, i);

            if(xcurr > bound)
                break;

            for(int j = 0; ; j++){
                long long ycurr = pow(y, j);
                long long curr = xcurr + ycurr;

                if(curr > bound)
                    break;

                if(mp[curr] == 0){
                    mp[curr]++;
                    ans.push_back(curr);
                }
                if(y==1)break;
            }

            if(x == 1)
                break;
        }

        return ans;
    }
};