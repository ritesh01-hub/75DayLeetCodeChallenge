class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans;

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;

                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }

            while (!ans.empty()) {
                int last = ans.back() - 'a';
                ans.pop_back();
                freq[last]++;

                
                for (int c = last + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        ans += char('a' + c);
                        freq[c]--;

                        // Fill suffix minimally
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

     
        while (!ans.empty()) {
            int last = ans.back() - 'a';
            ans.pop_back();
            freq[last]++;

            for (int c = last + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;

                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};