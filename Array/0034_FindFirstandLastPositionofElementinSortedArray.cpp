/*
** Binary Search：O(logn)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int rightBorder = getRightBorder(nums, target);
        int leftBorder = getLeftBorder(nums, target);
        
        // 情况一，不在範圍內
        if (leftBorder == -2 || rightBorder == -2) 
            return {-1, -1};
        // 情况三，在範圍內，但找有
        if (rightBorder - leftBorder > 1) 
            return {leftBorder + 1, rightBorder - 1};
        // 情况二，在範圍內，但找無
        return {-1, -1};
    }
    
private:
    int getRightBorder(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int rightBorder = -2;   // 未找到初始直
        
        while(l <= r){
            int mid = l + (r-l) / 2;    // 等同於 (left + right) / 2
            if(nums[mid] > target){
                r = mid - 1;
            }else{  // 當 nums[mid] <= target 時，更新 left，得到 target 右邊界
                l = mid + 1;
                rightBorder = l;
            }
        }
        
        return rightBorder;
    }
    
    int getLeftBorder(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int leftBorder = -2;    // 未找到初始直
        
        while(l <= r){
            int mid = l + (r-l) / 2;    // 等同於 (left + right) / 2
            if(nums[mid] >= target){    // 改成等於，當 nums[mid] >= target 時，更新 right，得到 target 左邊界
                r = mid - 1;
                leftBorder = r;
            }else{
                l = mid + 1;
            }
        }

        return leftBorder;
    }
};