class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<int> bits, bitg;
        while (start > 0) {
            bits.push_back(start & 1);
            start /= 2;
        }
        while (goal > 0) {
            bitg.push_back(goal & 1);
            goal /= 2;
        }
        reverse(bits.begin(), bits.end());
        reverse(bitg.begin(), bitg.end());

        if (bits.size() > bitg.size()) {
            int t = bits.size() - bitg.size();
            while (t--) {
                bitg.insert(bitg.begin(), 0);
            }
        }

        if (bits.size() < bitg.size()) {
            int t = bitg.size() - bits.size();
            while (t--) {
                bits.insert(bits.begin(), 0);
            }
        }

        int cnt = 0;

        for (int i = 0; i < bits.size(); i++) {
            cnt += (bits[i] ^ bitg[i]);
        }

        return cnt;
    }
};