/**
 * Hashmap
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;  // init
        for(int i = 0; i < nums.size(); i++)
            if(m.count(target - nums[i])) // Count elements with a specific key     如果存在，代表相減後的另一個值存在，即可返回答案
                return {m[target - nums[i]], i};
            else
                m.insert({nums[i], i}); // 不存在，即把當前值存入
        
        return {};
    }
};