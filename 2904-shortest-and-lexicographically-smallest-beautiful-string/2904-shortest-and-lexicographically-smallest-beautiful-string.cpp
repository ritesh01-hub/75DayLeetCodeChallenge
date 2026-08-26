class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        
        string ans = "";
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            
            if (s[right] == '1')
                ones++;

            // More than k ones -> shrink window
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Exactly k ones
            if (ones == k) {

                // Remove unnecessary leading zeros
                while (s[left] == '0')
                    left++;

                int len = right - left + 1;
                string curr = s.substr(left, len);

                // Shorter is better
                if (len < minLen) {
                    minLen = len;
                    ans = curr;
                }
                // Same length -> lexicographically smaller
                else if (len == minLen && curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};