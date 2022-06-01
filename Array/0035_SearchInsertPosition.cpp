/*
** Binary Search：O(logn)
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1; // init
        
        while(l<=r){
            int mid = l + (r - l) / 2;  // 防 overflow，等同於 (r+l)/2
            
            if(nums[mid] > target)  // nums[mid] 大於 target -> [l, mid - 1]
                r = mid - 1;
            else if(nums[mid] < target)    // nums[mid] 小於 target -> [mid + 1, r]
                l = mid + 1;
            else   // 到找
                return mid;   
        }
        
        return r + 1;   // 當 l=r 或是 target 目標在最後面
    }
};