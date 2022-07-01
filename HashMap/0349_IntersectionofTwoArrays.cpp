/**
 * Hashmap
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 由於在這裡使用數組版的 hashtable 並不實際(因為不像英文字母是有限制範圍的)
        unordered_set<int> ans;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());    // 將 nums1 先進行 set
        
        for(int n:nums2)
            if(nums_set.find(n) != nums_set.end())  // 將 nums2 丟到 nums1 set 後的結果進行尋找，如果 find 到的結果不是 end，代表有找到
                ans.insert(n);
        
        return vector<int>(ans.begin(), ans.end()); // 返回 vector
    }
};