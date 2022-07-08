/**
 * Hashmap
 */
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;  // init
        
        for(int n1 : nums1) // 遍歷前兩個，把所有出現的次數做一個統計
            for(int n2 : nums2)
                m[n1 + n2]++;
        
        int cnt = 0;
        for(int n3 : nums3) // 遍歷後兩個，如果減去後為零，表示該 key 的 value 為她出現的次數
            for(int n4 : nums4)
                if(m.count(0 - (n3 + n4)))  // 存在
                    cnt+=m[0 - (n3 + n4)];  
            
        return cnt;
    }
};