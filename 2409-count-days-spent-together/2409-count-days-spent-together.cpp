class Solution {
public:
    int countDaysTogether(string aa, string al, string ba, string bl) {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int a1 = stoi(aa.substr(0,2)), a2 = stoi(aa.substr(3,2));
        int a3 = stoi(al.substr(0,2)), a4 = stoi(al.substr(3,2));
        int b1 = stoi(ba.substr(0,2)), b2 = stoi(ba.substr(3,2));
        int b3 = stoi(bl.substr(0,2)), b4 = stoi(bl.substr(3,2));

        int start1 = a2, end1 = a4;
        int start2 = b2, end2 = b4;

        for(int i = 0; i < a1-1; i++) start1 += days[i];
        for(int i = 0; i < a3-1; i++) end1 += days[i];
        for(int i = 0; i < b1-1; i++) start2 += days[i];
        for(int i = 0; i < b3-1; i++) end2 += days[i];

        return max(0, min(end1,end2) - max(start1,start2) + 1);
    }
};
