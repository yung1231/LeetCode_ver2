/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
                if(fast == slow){   // 等於 代表有環的存在
                    ListNode* x = slow;
                    ListNode* y = head;
                    while(x != y){  // 再走 m 步到達入口點
                        x = x->next;
                        y = y->next;
                    }
                    return y;
                }
        }
        return NULL;
    }
};

// ![](https://i.imgur.com/Nwnuw7G.png)
// m 是到入口點
// k1 k2 圈數
// n 一圈的距離
// p 是快慢指針相遇的距離
// m+k1n+p = 2(m+k2np)
// (k1-2k2)n = p+m
// 當 (k1-2k2) = 1 時，意思是下面那一段就會是 m