class Solution {
public:
    int removeElement(vector<int>& nums, int val) { // 使用快慢指針(雙指針)來當作二層迴圈
        int slow = 0;   // 慢指針
        for(int fast = 0; fast < nums.size(); fast++)   // 快指針
            if(nums[fast] != val)
                nums[slow++] = nums[fast];
            
        return slow;
    }
};