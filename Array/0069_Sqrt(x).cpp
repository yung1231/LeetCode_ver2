/*
** Binary Search：O(logn)
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)  // 0 的情況單獨寫，因為如果不另外寫，當 x / mid 時會出問題
            return 0;
        
        int l = 1, r = x;
        
        // 想像成有一個 1 to x 的數組，在利用 binary search 的方式去找出目標值(可以這樣做是因為答案求的是整數，捨去小數部分)
        while(l <= r){
            int mid = l + (r - l) / 2;  // 防止 overflow
            
            if(mid > x / mid)   // 使用 x / mid 是為了防止 overflow
                r = mid - 1;
            else if(mid < x / mid)
                l = mid + 1;
            else
                return mid; // 剛好找到的情況下
        }
        
        return l - 1;   // 當 r < l 時，使用 l - 1
    }
};