/**
 * Linked List
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* tmp;  // 保存 curr 的下一個節點
        
        while(curr){
            tmp = curr->next;   // 存 curr 下一個節點
            curr->next = pre;   // curr 指回前一個節點
            pre = curr; // pre 往後移動
            curr = tmp; // curr 往後移動
        }
        
        return pre;
    }
};