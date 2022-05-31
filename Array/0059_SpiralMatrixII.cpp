class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int X = 0, Y = 0;   // 控制起始位置
        int count = 1;  // vector 內田入的數字
        int loop = n / 2;   // 要重複的圈數
        int i, j;   // 要用來移動的指標
        int offset = 1; // 每次 loop 每個動作要預留的空位
        
        while(loop){
            i = X;
            j = Y;
            
            // 要預留一個空格，也就是 3 長度的話只能用 2 長度，5 長度的話只能用 4 長度
            for(; j < Y + n - offset; j++)  // 上左到上右
                ans[i][j] = count++;
            
            for(; i < X + n - offset; i++)  // 右上到右下
                ans[i][j] = count++;
            
            for(; j > Y; j--)   // 下右到下左
                ans[i][j] = count++;
            
            for(; i > X; i--)   // 左下到左上
                ans[i][j] = count++;
            
            X++;
            Y++;
            offset+=2;
            loop--;
        }
        
        if(n%2) // 基數圈的話，中間會是空的，沒處裡到
            ans[n/2][n/2] = count;
        
        return ans;
    }
};