/*
** Binary Search：O(logn)
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num; // init
        
        while(l <= r){  // 這裡做了一下判斷條件的順序變換，排除進入無限迴圈
            int mid = l + (r - l) / 2;
            if(mid == num / mid && num % mid == 0)  // 用 % 是因為 / 是只取整數，因此要用 % 來確定是否整除
                return true;
            else if(mid > num / mid)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        
        return false;
    }
};

// 2000105819