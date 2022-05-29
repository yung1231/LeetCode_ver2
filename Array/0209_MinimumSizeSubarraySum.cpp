class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0, sum = 0, subLen = 0, ans = nums.size() + 1;  // init
        
        // 雙指標 滑動窗口
        for(int i = 0; i < nums.size(); i++){   // j 固定，i 往前
            sum += nums[i]; // 累加
            while(sum >= target){   // 當累加值大於等於目標值，就持續從最前面減回去，直到小於目標值
                subLen = i - j + 1;
                ans = subLen < ans ? subLen : ans;  // 判斷目前最短長度
                sum -= nums[j++];   // 減掉過去值
            }
        }
        
        return ans == nums.size() + 1 ? 0 : ans;    // 判斷結果是否與原本初始值不一樣
    }
};