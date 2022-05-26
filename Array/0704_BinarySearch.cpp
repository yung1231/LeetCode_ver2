class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;  // init
        
        while(l <= r){
            m = (r - l) / 2 + l;    // Prevent overflow equivalent to (left + right)/2
            
            if(nums[m] > target)
                r = m - 1;  // [l, m-1]
            else if(nums[m] < target)
                l = m + 1;  // [m+1, r]
            else
                return m;   // nums[m] == target, find
        }
        
        return -1;  // Not find
    }
};