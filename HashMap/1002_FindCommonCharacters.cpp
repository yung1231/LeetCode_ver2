/**
 * Hashmap
 */
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        int minTable[26] = {0};        
        
        for(int i = 0; i < words[0].size(); i++)    // 以第一組 word 當作初始值
            minTable[words[0][i] - 'a']++;
    
        for(int i = 1; i < words.size(); i++){
            int tmpTable[26] = {0};
            for(int j = 0; j < words[i].size(); j++)    // 建立一個臨時的 table，用來儲存其他的 word 值
                tmpTable[words[i][j] - 'a']++;   
            for(int j = 0; j < 26; j++) // 將最小的值取出來，也就是指最小出現的次數
                minTable[j] = min(minTable[j], tmpTable[j]);
        }
        
        for(int i = 0; i < 26; i++){    // 將 table 裡面不為零的值輸出
            while(minTable[i] != 0){
                string s(1, i + 'a'); // char -> string (構造函數)
                ans.push_back(s);
                minTable[i]--;
            }
        }        
        
        return ans;
    }
};