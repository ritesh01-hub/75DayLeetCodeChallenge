class Solution {
public:
    const long long LIMIT = 1000001;

    // Count distinct permutations:
    // n! / (c1! * c2! * ...)
    // but cap answer at LIMIT
    long long countPerm(vector<int>& cnt, int n) {
        long long ans = 1;
        int used = 0;

        for (int x : cnt) {
            for (int j = 1; j <= x; j++) {
                used++;

                // C(used, j) update
                ans = ans * used / j;

                if (ans >= LIMIT)
                    return LIMIT;
            }
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        char middle = 0;
        vector<int> cnt(26);

        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                middle = 'a' + i;

            cnt[i] = freq[i] / 2;
            halfLen += cnt[i];
        }

        // Check total number of palindromic permutations
        if (countPerm(cnt, halfLen) < k)
            return "";

        string left;

        // Construct k-th lexicographically smallest half
        for (int pos = 0; pos < halfLen; pos++) {

            for (int ch = 0; ch < 26; ch++) {

                if (cnt[ch] == 0)
                    continue;

                // Try putting this character here
                cnt[ch]--;

                long long ways = countPerm(
                    cnt,
                    halfLen - pos - 1
                );

                if (k > ways) {
                    // Skip all permutations beginning with this choice
                    k -= ways;
                    cnt[ch]++;
                }
                else {
                    // k-th permutation lies in this block
                    left.push_back('a' + ch);
                    break;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (middle)
            return left + middle + right;

        return left + right;
    }
};