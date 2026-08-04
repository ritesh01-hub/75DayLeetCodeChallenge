class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        // int n= nums.size();


        // vector<int> ans;
        // int sum = 0;
        // int totalSum = 0;
        // for(int i =0;i<n;i++){
        //     sum += nums[i];
        // }

        // for(int i =0;i<=n;i++){
        //     totalSum += nums[i];
        // }
        // ans.push_back(totalSum-sum);

        // return ans;

        vector<int> ans;
        sort(nums.begin(),nums.end());

        for(int i = nums[0]+1;i<nums.back();i++){
            if(!binary_search(nums.begin(),nums.end(), i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};