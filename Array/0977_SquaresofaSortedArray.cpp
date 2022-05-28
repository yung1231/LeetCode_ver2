class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> ans(nums.size());   // init
        
        // 雙指針法
        for(int l = 0, r = nums.size() - 1; l <= r;)    // l=r 時要考慮進去
            if(abs(nums[l]) < abs(nums[r])) // 取整數後，大的一樣大，小的一樣小
                ans[n--] = nums[r] * nums[r--];
            else
                ans[n--] = nums[l] * nums[l++];
        
        return ans;
    }
};

// 暴力解
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& A) {
//         for (int i = 0; i < A.size(); i++) {
//             A[i] *= A[i];
//         }
//         sort(A.begin(), A.end()); // 快速排序
//         return A;
//     }
// };