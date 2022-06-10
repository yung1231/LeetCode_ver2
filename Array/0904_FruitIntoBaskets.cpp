/*
** Sliding Window
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> table;    // 籃子：fruit -> idx
        int l = 0, r = 0, ans = 0;  // init
        
        while(r < fruits.size()){
            table[fruits[r]]++;
            while(table.size() > 2){    // 當籃子內種類大於 2 時，開始刪除最前面的種類
                if(--table[fruits[l]] == 0) // 刪除直到歸零
                   table.erase(fruits[l]);  // 從籃子中移除
                l++;
            }
            ans = max(ans, r++ - l + 1);    // 選擇出當前的最大距離
        }
        
        return ans;
    }
};
// [3,3,3,1,2,1,1,2,3,3,4]