/**
 * Hashmap
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        int table[26] = {0};
        
        if(s.length() != t.length())
            return false;
        
        // 利用 ascii 的數值差，來當作 index
        for(int i = 0; i < s.length(); i++) // 計算 s 
            table[s[i] - 'a']++;
        
        for(int i = 0; i < t.length(); i++) // 計算 t
            table[t[i] - 'a']--;
            
        
        for(int i = 0; i < 26; i++) // 若有不為 0 的數，代表 2 個字串內容不相等
            if(table[i] != 0)
                return false;
        
        return true;
    }
};