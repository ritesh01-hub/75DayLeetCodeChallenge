class Solution {
public:
    int maxArea(vector<int>& height) {
            // brute force:
    //     int mxans =0;
    //     for(int i =0;i<height.size();i++){
    //         for(int j=i+1;j<height.size();j++){
    //             int wt = j-i;
    //             int hgt = min(height[i],height[j]);
    //             int wtcontain = wt*hgt;
    //             mxans = max(mxans , wtcontain);
    //         }
          
    //     }
    //       return mxans;



        int maxwater = 0;//ans
        int left =0,right =height.size()-1;

        while(left<right){
            int w = right -left;
            int ht =min(height[left],height[right]);
            int currwater = w*ht;

            maxwater = max(maxwater,currwater );

            height[left]<height[right]? left++:right--;

        }
        return maxwater;
    }
};