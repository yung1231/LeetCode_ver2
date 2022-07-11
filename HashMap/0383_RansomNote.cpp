/**
 * Hashmap
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int table[26] = {0};    // init table
        
        for(char i : magazine)  // 將 magazine 裡的字先儲存到 table 中
            table[i - 'a']++;        
        for(char i : ransomNote)    // 將 ransomNote 裡出現在 table 的字扣掉，若為負數，代表說出現次數大於在 ransomNote 中所出現的次數
            if(--table[i - 'a'] < 0)
                return false;
        
        return true;
    }
};