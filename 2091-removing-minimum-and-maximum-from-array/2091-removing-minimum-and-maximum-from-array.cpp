class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int idxMin = 0;
        int idxMax = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] < nums[idxMin]){
                idxMin = i;
            }
            if(nums[i] > nums[idxMax]){
                idxMax = i;
            }
        }
          int left = min(idxMin, idxMax);
          int right = max(idxMin, idxMax);

           int fromFront = right + 1;

    
        int fromBack = n - left;

        
        int fromBoth = (left + 1) + (n - right);

        return min({fromFront, fromBack, fromBoth});
    }
};