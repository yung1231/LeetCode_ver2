/**
 * String
 */
class Solution {
public:   
    // step1: 先反轉整個字串
    // step2: 移除空格
    // step3: 對每個單詞進行反轉
    string reverseWords(string s) {
        removeExtraSpaces(s); 
        reverseString(s, 0, s.size() - 1);    // 一開始先將整個字串做翻轉
        
        int start = 0;  // 紀錄一個單詞開頭的位置
        for(int i = 0; i <= s.size(); ++i){
            if(i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverseString(s, start, i - 1);   // 翻轉單詞
                start = i + 1;  // 更新單詞開頭位置
            }
        }
        
        return s;
    }
    
    void reverseString(string& s, int start, int end) { // 反轉字串
        for(int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);  
    }
    
    void removeExtraSpaces(string& s){   // 移除多於的空格
        int sl = 0;
        for(int fa = 0; fa < s.size(); fa++){
            if(s[fa] != ' '){ //遇到非空格就处理，即删除所有空格。
                if(sl != 0) // 排除最一開始就要加空格的情況
                    s[sl++] = ' ';  // 單詞跟單詞之間加上空格
                while(fa < s.size() && s[fa] != ' ')    // 找單詞
                    s[sl++] = s[fa++];
            }
        }
                
        s.resize(sl); // 重設字串大小
    }
};