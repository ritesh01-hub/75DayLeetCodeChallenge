class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int total = 0;
        for(int i =0;i<n; i++){
            total += (i/8)+1;
        }
        return total;
    }
};