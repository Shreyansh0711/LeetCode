class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < n; i++) {

            int ch = target[i] - 'a';
            if (cnt[ch] > 0) {
                ans += target[i];
                cnt[ch]--;
            } 
            else {
                break;
            }
        }

        int m = ans.size();
        if (m < n) {
            int ch = target[m] - 'a';
            for (int k = ch + 1; k < 26; k++) {
                if (cnt[k] > 0) {
                    ans += char('a' + k);
                    cnt[k]--;
                    for (int x = 0; x < 26; x++) {
                        ans += string(cnt[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            cnt[ans.back() - 'a']++;
            ans.pop_back();

            int ch = target[j] - 'a';
            for (int k = ch + 1; k < 26; k++) {
                if (cnt[k] > 0) {

                    ans += char('a' + k);
                    cnt[k]--;
                    for (int x = 0; x < 26; x++) {
                        ans += string(cnt[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};