/**
 * String
 */
class Solution {
public:    
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i+=2*k)  // 每隔 2k 個進行反轉
            if(i + k <= s.length()) // 如果少於 k 個的話，就正常地進行交換
                for(int j = i, l = i + k - 1; j < l; j++, l--)
                    swap(s[j], s[l]);
            else    // 反之 指交換到在 s 長度內的數量
                for(int j = i, l = s.length() - 1; j < l; j++, l--)
                    swap(s[j], s[l]);

        return s;
    }
};