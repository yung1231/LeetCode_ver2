/**
 * Linked List + Two pointer
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        
        while(fast != NULL && n--)  // 預先移動 n + 1 步，來使快指針能夠優先指到最後一個節點
            fast = fast->next;
        fast = fast->next;
        
        while(fast != NULL){    // 迴圈結束時，fast 已經到了最後一個節點的下一個(null)，而 slow 會指向要刪除的前一個節點
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;  // 移除中間要刪除的節點
         
        return dummyHead->next;
    }
};