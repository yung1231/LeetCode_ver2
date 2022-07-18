/**
 * String
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size()- 1; i < j ; i++, j--)   // 使用雙指針的方式
            swap(s[i], s[j]); 
    }
};