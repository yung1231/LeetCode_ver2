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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);  // 虛擬頭節點
        ListNode* curr = dummyHead; // 當前節點
        dummyHead->next = head;
        
        while(curr->next != nullptr && curr->next->next != nullptr){    // 確保存在兩個連續的節點(空間)
            ListNode* first = curr->next; // 紀錄保存第一個節點
            ListNode* second = curr->next->next;  // 記錄保存第二個節點
            
            // 順序很重要!!!
            curr->next = second;  // 當前節點指向第二個節點
            first->next = second->next;    // 第一個節點指向第二個節點的下一個節點
            second->next = first;  // 第二個節點指回第一個節點
            
            curr = curr->next->next;    // 移動到下一對的前一個
        }
        
        return dummyHead->next;
    }
};
// 畫個圖比較清楚 ^_^