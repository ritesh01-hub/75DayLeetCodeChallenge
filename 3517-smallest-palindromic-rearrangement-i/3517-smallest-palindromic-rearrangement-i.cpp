class Solution {
public:
    string smallestPalindrome(string s) {
         vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        char middle = '\0';

        for (int i = 0; i < 26; i++) {

            // Put half occurrences on left
            left += string(freq[i] / 2, 'a' + i);

            // Odd frequency => middle character
            if (freq[i] % 2 == 1) {
                middle = 'a' + i;
            }
        }
         string right = left;
        reverse(right.begin(), right.end());

        if (middle != '\0') {
            return left + middle + right;
        }

        return left + right;
    }
};