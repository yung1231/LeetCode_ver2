/*
** Two pointer
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){   // i 用來當作固定不變的指針
            if(nums[i] > 0) // 因為排序後，如果最前面固定的指針已經大於零了，代表說後面的數一定大於零，絕對不可能相加後會能夠等於 0
                return ans;
            if(i > 0 && nums[i] == nums[i - 1]) // 去除固定指針的重複
                continue;
            
            int l = i + 1;  // 左指針
            int r = nums.size() - 1;    // 右指針
            while(l<r){
                if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) // 如果 -- 後，還是與原本的重複了，就一直重複 -- 的動作，直到不重複
                        r--;
                }else if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) // 如果 ++ 後，還是與原本的重複了，就一直重複 ++ 的動作，直到不重複
                        l++;
                }else{  // 等於 0 表示為答案
                    ans.push_back(vector<int> {nums[i], nums[l], nums[r]}); // 把答案加入
                    while (l < r && nums[r] == nums[r - 1]) // 去除接下來的重複，因為這樣子答案會是重複的
                        r--;
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    r--;    // 往下一個位置指
                    l++;
                }              
            }
        }
        
        return ans;
    }
};