class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(),nums.end());
        int val = k;
        while(seen.count(val)){
            val += k;
        }
        return val;
    }
};