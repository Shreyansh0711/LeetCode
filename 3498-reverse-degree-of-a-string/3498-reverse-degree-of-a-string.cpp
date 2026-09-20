class Solution {
public:
    int reverseDegree(string s) {
        int i=1,sm=0;
        for(char c:s){
            sm+=i*(26-(c-'a'));
            i++;
        }
        return sm;
    }
};