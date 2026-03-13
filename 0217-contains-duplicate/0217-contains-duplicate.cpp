class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // brute force 
        /// using two loops || two pointers
        // int n = nums.size();
        // for(int i =0;i<n;i++){
        //     for(int  j = i+1;j<n;j++){
        //         if(nums[i] == nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        unordered_set<int> s;

        for(int x : nums){
            if(s.count(x)){
                return true;
            }
            s.insert(x);
        }

        return false;
    }
};