class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) { odd++; mid = 'a' + i; }
        }
        if (odd > 1) return "";

        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++) halfCnt[i] = cnt[i] / 2;

        int m = n / 2;

        // 1) Try full exact match of target's half FIRST (longest possible prefix match)
        {
            vector<int> rem = halfCnt;
            string half;
            bool feasible = true;

            for (int i = 0; i < m; i++) {
                int x = target[i] - 'a';
                if (rem[x] == 0) { feasible = false; break; }
                half += target[i];
                rem[x]--;
            }

            if (feasible) {
                string ans = half;
                if (n % 2) ans += mid;
                string rev = half;
                reverse(rev.begin(), rev.end());
                ans += rev;
                if (ans > target) return ans;
            }
        }

        
        for (int pos = m - 1; pos >= 0; pos--) {
            vector<int> rem = halfCnt;
            string half;
            bool possible = true;

            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';
                if (rem[x] == 0) { possible = false; break; }
                half += target[i];
                rem[x]--;
            }
            if (!possible) continue;

            int t = target[pos] - 'a';
            int bigger = -1;
            for (int c = t + 1; c < 26; c++) {
                if (rem[c] > 0) { bigger = c; break; }
            }
            if (bigger == -1) continue;

            half += char('a' + bigger);
            rem[bigger]--;

            for (int c = 0; c < 26; c++)
                while (rem[c] > 0) { half += char('a' + c); rem[c]--; }

            string ans = half;
            if (n % 2) ans += mid;
            string rev = half;
            reverse(rev.begin(), rev.end());
            ans += rev;

            if (ans > target) return ans;
        }

        return "";
    }
};