class Solution {
public:
    int numberOfRounds(string li, string lo) {
        int s = stoi(li.substr(0,2))*60 + stoi(li.substr(3,2));
        int e = stoi(lo.substr(0,2))*60 + stoi(lo.substr(3,2));

        if(e < s) e += 24*60;

        int start = (s + 14)/15;
        int end = e/15;

        return max(0, end-start);
    }
};