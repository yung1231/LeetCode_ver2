class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {        
        int row = matrix.size(), column = matrix[0].size();   // row、column 數量
        int loop = min(row, column) / 2;   // 循環次數，因為不是方陣，所以取最小的
        int X = 0, Y = 0;   // 每次 loop 的起始位置
        int i = 0, j = 0;   // 當前遍歷位置        
        int mid = min(row, column); //  用於處裡最後的剩餘情況
        int offset = 1; // 偏移量
        int count = 0;  // 用於 ans 的 index
        vector<int> ans(row * column);
        
        while(loop){
            i = X; 
            j = Y;
            
            for(; j < Y + column - offset; j++) // 上左到上右
                ans[count++] = matrix[i][j];
            
            for(; i < X + row - offset; i++)    // 右上到右下      
                ans[count++] = matrix[i][j];
            
            for(; j > Y; j--)   // 下右到下左
                ans[count++] = matrix[i][j];
            
            for(; i > X; i--)   // 左下到左上
                ans[count++] = matrix[i][j];
            
            X++;
            Y++;
            loop--;
            offset+=2;
        }
        
        if(mid % 2 != 0)   // 不等於 0 表示非方陣
            if(row > column)   // 若 row 大，代表 row 要繼續移動，column 要固定
                for(i = mid; i < mid + row - column + 1; i++)
                    ans[count++] = matrix[X++][Y];
            else  // 若 column 大，代表 column 要繼續移動，row 要固定
                for(i = mid; i < mid + column - row + 1; i++)
                    ans[count++] = matrix[X][Y++];
        
        return ans;
    }
};
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
// [[1]]