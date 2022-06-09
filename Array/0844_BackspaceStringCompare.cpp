/*
** Two pointer
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = 0, n = 0;   // init
        
        for(int i = 0; i < s.size(); i++)   // 在 s 中，使用 m 來記錄指向要被更改的位置
            if(s[i] == '#')
                m = max(--m, 0);    // 先將 m 減 1，回到上一個位置，代表著被刪除的意思(m 不會是負數
            else
                s[m++] = s[i];  // 不等於 # 時，將 m 等於當前 i 所指向的位置，最後 m 向前移動到下一個位置
        
        for(int i = 0; i < t.size(); i++)   // 重複 s 中的動作
            if(t[i] == '#')
                n = max(--n, 0);
            else
                t[n++] = t[i];
            
        if(m!=n)    // 如果長度不一樣，代表字串內容一定不一樣
            return false;   
        else
            for(int i = 0; i < m; i++)  // 比較字串內容是否相等
                if(s[i] != t[i])
                    return false;
                 
        return true;
    }
};