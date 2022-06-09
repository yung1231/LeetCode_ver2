/*
** Two pointer
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l, r;   // init
        
        for(l = 0, r = 0; r < nums.size(); r++)
            if(nums[r] != 0)    // 如果不等於零就交換
                nums[l++] = nums[r];
        
        // 把剩下的都清零
        while(l < nums.size())
            nums[l++] = 0;
    }
};