class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        /// using cyclic sort algo
        while(i<n){
            int corrIdx = nums[i] -1;
            if(nums[corrIdx] == nums[i] || corrIdx == i) i++;
            else swap(nums[i],nums[corrIdx]);
        }
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};