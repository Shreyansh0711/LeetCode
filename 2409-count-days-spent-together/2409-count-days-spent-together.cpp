class Solution {
public:
    int countDaysTogether(string aa, string al, string ba, string bl) {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        auto convert = [&](string s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));
            int ans = day;

            for (int i = 0; i < month - 1; i++) {
                ans += days[i];
            }

            return ans;
        };

        int aar = convert(aa);
        int aal = convert(al);
        int bar = convert(ba);
        int bal = convert(bl);

        return max(0, min(aal, bal) - max(aar, bar) + 1);
    }
};
