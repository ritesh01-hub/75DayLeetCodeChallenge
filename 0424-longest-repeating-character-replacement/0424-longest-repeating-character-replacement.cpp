class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    for (int right = 0; right < s.size(); right++) {
        // update frequency
        freq[s[right] - 'A']++;

        // update max frequency in window
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // check if window is valid
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }
            // update answer
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
    }
};