class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left  = 0;
        int results = 0;
        vector<int> freq(256,0);
        for(int i = 0;i<s.length();i++){
            freq[s[i]]++;
            while(freq[s[i]]>1){
                freq[s[left]]--;
                left++;
            }
            results = max(results,i-left +1);
        }
        return results;
    }
};