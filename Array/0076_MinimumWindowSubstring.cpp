/*
** Sliding Window
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, cnt = 0, min_num = INT_MAX;
        string ans = "";
        unordered_map<char, int> table;

        for(auto c:t)   // 將 t 中的字元，對其統計數量
            table[c]++;
        
        for(;r < s.size(); r++){
            if(--table[s[r]] >= 0)  // 若對應的字元還有，代表著還不滿足 t
                cnt++;

            while(cnt == t.size()){ // 若字元數等於 t 長度，表示目前已包含了 t 的內容，開始處裡
                if(min_num > r - l + 1){    // 統計長度
                    min_num = r - l + 1;
                    ans = s.substr(l, min_num); // 子字串
                }
                
                if(++table[s[l]] > 0)   // 大於 0，代表恢復了原本儲存的內容，可以繼續往後比較
                    cnt--;
                l++;
            }
        }
        
        return ans;
    }
};