class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // using prifix and suffix approach
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        vector<int> ans(n);
        //prefix product 
        int p = nums[0];
        pre[0]= 1;
        for(int i =1;i<n;i++){
            pre[i] = pre[i-1]*nums[i-1];
            // pre[i] = p;
            // p*=nums[i];


        }
        // suffix product
        p = nums[n-1];
        suf[n-1] = 1;
        for(int i =n-2;i>=0;i--){
            suf[i]= suf[i+1]*nums[i+1];
            // suf[i] = p;
            // p*= nums[i];
        }
        // pre[i] = pre[i]*suf[i]
        for(int i =0;i<n;i++){
            ans[i] = pre[i]*suf[i];

        
       // pre[i] = pre[i]*suf[i];
        }

        return ans;
    }
    
};