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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);   // 設置假頭節點
        dummyHead->next = head; // 連接到原始的 head
        ListNode* curr = dummyHead; // 用於紀錄當前所遍歷到的位置
        
        while(curr->next != NULL){
            if(curr->next->val == val){
                ListNode* tmp = curr->next; // 將要被移除的節點記錄起來
                curr->next = curr->next->next;  // 將要被移除的節點的下一個節點，連到目前的節點上
                delete tmp; // 刪除要移除的節點
            }else{
                curr = curr->next;  // 到下一個位置
            }
            
        }
        head = dummyHead->next; // 返回原始的 head 作為答案
        delete dummyHead;   // 刪除假頭節點
        
        return head;
    }
};