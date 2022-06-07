/*
** Two pointer
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;   // init
        
        for(i = 0, j = 0; j < nums.size(); j++)
            if(nums[i] != nums[j])  
                nums[++i] = nums[j];    // 先 ++ 是因為當前所指向的是比較的，當遇到不一樣的，那下一個是要被替換掉的   
            
        return i+1;
    }
};
// [0,0,1,1,1,2,2,3,3,4]


// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int cnt = 1;
//         for(int i = 1; i < nums.size(); i++)
//             if(nums[i] != nums[i-1])
//                 nums[cnt++] = nums[i];   
            
//         return cnt;
//     }
// };

