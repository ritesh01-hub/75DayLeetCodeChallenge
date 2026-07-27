class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int sMax = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxi) {
                sMax = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > sMax) {
                sMax = nums[i];
            }
        }

        return (maxi - 1) * (sMax - 1);
    }
};