class Solution {
public:
    int search(vector<int>& arr, int target) {
        // always works on sorted arrays
        int n = arr.size();
        int lo =0;
        int hi = n-1;
        int idx = -1;
       bool flag = false;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid]==target){
                flag = true;
                idx = mid;
                break;
            }
            //if(flage == true) break;
            else if(arr[mid]>target) hi = mid -1;
            else lo= mid+1;

            
        }
        return idx;
        
    } 
};