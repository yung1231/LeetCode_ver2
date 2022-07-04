/**
 * Hashmap
 */
class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        while(n){   // 計算每個位數平方後的值並累加
            sum += (n%10) * (n%10);
            n/=10;
        }
        if(sum == 1)    // 等於 1 表示是 happy number
            return true;
        else if(s.count(sum))   // else if(s.find(sum) != s.end())：另一種判斷是否存在的寫法         如果已存在，代表會一直重複計算該數字，也就是會出現無窮迴圈
            return false;
        else
            s.insert(sum);
        
        return isHappy(sum);    // 遞迴繼續下一次的計算
    }
    
private:
    unordered_set<int> s;
};